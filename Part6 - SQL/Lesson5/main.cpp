#include <iostream>
#include <pqxx/pqxx>

#include <Windows.h>

int get_client_id(pqxx::work& tr, const std::string& name, const std::string& surname) {
	auto c_res = tr.query<int>("SELECT id FROM public.client c WHERE c.name = '"
		+ tr.esc(name) + "' AND c.surname = '" + tr.esc(surname) + "'");

	if (c_res.begin() == c_res.end()) {
		std::string out = "Client: " + name + " " + surname + " doesn't registered!";
		std::exception ex{ out.c_str() };
		throw ex;
	}

	auto get_id = [&](const auto& r)->int {
		std::tuple<int> t = *(r.begin());

		return std::get<0>(t);
		};

	return get_id(c_res);
}

int get_client_id_by_email(pqxx::work& tr, const std::string& email) {
	auto c_res = tr.query<int>("SELECT id FROM public.client c WHERE c.email = '"
		+ tr.esc(email) + "'");

	if (c_res.begin() == c_res.end()) {
		return -1;
	}

	auto get_id = [&](const auto& r)->int {
		std::tuple<int> t = *(r.begin());

		return std::get<0>(t);
		};

	return get_id(c_res);
}

int get_client_id(pqxx::work& tr, const std::string& number) {
	auto c_res = tr.query<int>("SELECT client_id FROM public.phonenumber pn WHERE pn.number = '"
		+ tr.esc(number));

	if (c_res.begin() == c_res.end()) {
		std::string out = "Number: " + number + " doesn't registered!";
		std::exception ex{ out.c_str() };
		throw ex;
	}

	auto get_id = [&](const auto& r)->int {
		std::tuple<int> t = *(r.begin());

		return std::get<0>(t);
		};

	return get_id(c_res);
}

void delete_phone(pqxx::connection& conn, const std::string& name, const std::string& surname, const std::string& phone_to_delete = "") {
	pqxx::work tr(conn);

	int c_id = get_client_id(tr, name, surname);

	if (phone_to_delete != "") {
		auto pn_res = tr.query<int>("SELECT id FROM public.phonenumber pn WHERE pn.number = '" + tr.esc(phone_to_delete) + "'");
		if (pn_res.begin() == pn_res.end()) {
			std::string out = "Number: " + phone_to_delete + " doesn't registered!";
			std::exception ex{ out.c_str() };
			throw ex;
		}

		int pn_id = std::get<0>((*pn_res.begin()));

		tr.exec("DELETE FROM public.phonenumber WHERE id = " + std::to_string(pn_id));
	}
	else {
		tr.exec("DELETE FROM public.phonenumber WHERE client_id = " + std::to_string(c_id));
	}

	tr.commit();
}

void delete_client(pqxx::connection& conn, const std::string& name, const std::string& surname) {
	delete_phone(conn, name, surname);

	pqxx::work tr(conn);

	tr.exec("DELETE FROM public.client WHERE name = '" + tr.esc(name) + "' AND surname = '" + tr.esc(surname) + "'");

	tr.commit();
}

void change_email(pqxx::connection& conn, const std::string& name, const std::string& surname, const std::string& email) {
	pqxx::work tr(conn);

	int c_id = get_client_id(tr, name, surname);
	int c_id_by_email = get_client_id_by_email(tr, email);
	if (c_id_by_email >= 0 && c_id != c_id_by_email) {
		std::string out = "Email: " + email + "already registered for other client!";
		std::exception ex{ out.c_str() };
		throw ex;
	}

	tr.exec("UPDATE public.client SET email = '" + tr.esc(email) +
		"' WHERE id = " + std::to_string(c_id));

	tr.commit();
}

void add_number(pqxx::connection& conn, const std::string& number, const std::string& name, const std::string& surname) {
	pqxx::work tr(conn);

	int c_id = get_client_id(tr, name, surname);

	auto ress = tr.query<int>("SELECT id FROM public.phonenumber pn WHERE pn.number = '" + tr.esc(number) + "'");
	if (ress.begin() != ress.end()) {
		std::string out = "Number: " + number + " already registered";
		std::exception ex{out.c_str()};
		throw ex;
	}
		
	tr.exec("INSERT INTO public.phonenumber(client_id, number)"
		"VALUES(" + std::to_string(c_id) + ", '" + tr.esc(number) + "')");

	tr.commit();
}

void add_client(pqxx::connection& conn, const std::string& name, const std::string& surname, const std::string& email = "") {
	pqxx::work tr(conn);

	auto res = tr.query<int>("SELECT id FROM public.client c WHERE c.name = '" + tr.esc(name) + "'AND c.surname = '" + tr.esc(surname) + "'");

	if (res.begin() != res.end()) {
		std::exception ex{ "Client already registered!" };
		throw ex;
	}
		

	tr.exec("INSERT INTO public.Client(name, surname, email) "
		"VALUES('" + tr.esc(name) + "', '" + tr.esc(surname) + "', '" + tr.esc(email) + "')");

	tr.commit();
}

void create_database_structure(pqxx::connection& conn) {
	pqxx::work tr(conn);

	tr.exec("create table if not exists public.Client(id serial primary key, "
		"name varchar(60) not null, "
		"surname varchar(60) not null, "
		"email text)");

	tr.exec("create table if not exists public.PhoneNumber(id serial primary key, "
		"client_id integer references public.Client(id), "
		"number text not null)");

	tr.commit();
}

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	try {
		pqxx::connection conn{ "host = 127.0.0.1 "
							  "port=5432 "
							  "dbname=clients "
							  "user=postgres "
							  "password=secret" };

		create_database_structure(conn);

		add_client(conn, "Danil", "Lizov");

		add_number(conn, "89088822908", "Danil", "Lizov");

		change_email(conn, "Danil", "Lizov", "ggg@gmail.com");

		delete_phone(conn, "Danil", "Lizov", "89088822908");

		delete_client(conn, "Danil", "Lizov");
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	
	return 0;
}