#include "ClientManager.hpp"

Client::Client(pqxx::work& tr, int clientId)
{
	refreshData(tr, clientId);
}

Client::Client(const Client& cl)
{
	m_data = cl.m_data;
	m_numbers = cl.m_numbers;
}

Client::Client(Client&& cl) noexcept
{
	m_data = std::move(cl.m_data);
	m_numbers = std::move(cl.m_numbers);
}

void Client::operator=(const Client& cl)
{
	m_data = cl.m_data;
	m_numbers = cl.m_numbers;
}

void Client::operator=(Client&& cl) noexcept
{
	m_data = std::move(cl.m_data);
	m_numbers = std::move(cl.m_numbers);
}

int Client::getId() const
{
	return std::get<0>(m_data);
}

std::string Client::getName() const
{
	return std::get<1>(m_data);
}

std::string Client::getSurname() const
{
	return std::get<2>(m_data);
}

std::string Client::getEmail() const
{
	return std::get<3>(m_data);
}

std::vector<std::tuple<int, std::string>> Client::getNumbers() const
{
	return m_numbers;
}

void Client::updateData(pqxx::work& tr, const std::string& name, const std::string& surname, const std::string& email)
{
	tr.exec("UPDATE public.client SET name = '" + tr.esc(name) +
		"', surname = '" + tr.esc(surname) +
		"', email = '" + tr.esc(email) +
		"' WHERE id = " + std::to_string(getId()));

	tr.commit();
}

void Client::addNumber(pqxx::work& tr, const std::string& number)
{
	auto ress = tr.query<int>("SELECT id FROM public.phonenumber pn WHERE pn.number = '" + tr.esc(number) + "'");
	if (ress.begin() != ress.end()) {
		std::string out = "Number: " + number + " already registered";
		std::exception ex{ out.c_str() };
		throw ex;
	}

	tr.exec("INSERT INTO public.phonenumber(client_id, number)"
		"VALUES(" + std::to_string(std::get<0>(m_data)) + ", '" + tr.esc(number) + "')");

	tr.commit();
}

void Client::deleteNumber(pqxx::work& tr, int numberId)
{
	tr.exec("DELETE FROM public.phonenumber WHERE id = " + std::to_string(numberId));

	tr.commit();
}

void Client::deleteItself(pqxx::work& tr)
{
	for (auto num : m_numbers)
		tr.exec("DELETE FROM public.phonenumber WHERE id = " + std::to_string(std::get<0>(num)));

	tr.exec("DELETE FROM public.client WHERE id = " + std::to_string(getId()));

	tr.commit();
}

void Client::refreshData(pqxx::work& tr, int clientId)
{
	m_data = tr.query1<int, std::string, std::string, std::string>("SELECT id, name, surname, email "
		"FROM public.client c WHERE c.id = " + std::to_string(clientId));

	auto pn_res = tr.query<int, std::string>("SELECT id, number FROM public.phonenumber pn WHERE "
		"pn.client_id = " + std::to_string(clientId));

	m_numbers.clear();
	for (std::tuple<int, std::string> row : pn_res)
		m_numbers.push_back(row);
}

ClientManager::ClientManager() {
	m_connecton = std::make_unique<pqxx::connection>("host = 127.0.0.1 "
							  "port=5432 "
							  "dbname=clients "
							  "user=postgres "
							  "password=secret" );

	refreshClients();
}

ClientManager::~ClientManager()
{
}

void ClientManager::initDbStrucuture()
{
	pqxx::work tr(*m_connecton);

	tr.exec("create table if not exists public.Client(id serial primary key, "
		"name varchar(60) not null, "
		"surname varchar(60) not null, "
		"email text)");

	tr.exec("create table if not exists public.PhoneNumber(id serial primary key, "
		"client_id integer references public.Client(id), "
		"number text not null)");

	tr.commit();
}

void ClientManager::refreshClients()
{
	pqxx::work tr(*m_connecton);

	auto res = tr.query<int>("SELECT id FROM public.client");

	m_clients.clear();
	for (const auto row : res)
		m_clients.push_back({ tr, std::get<0>(row) });
}

int ClientManager::addClient(const std::string& name, const std::string& surname, const std::string& email)
{
	pqxx::work tr(*m_connecton);

	auto res = tr.query<int>("SELECT id FROM public.client c WHERE c.name = '" + tr.esc(name) + "'AND c.surname = '" + tr.esc(surname) + "'");

	if (res.begin() != res.end()) {
		std::tuple<int> t = *res.begin();
		return std::get<0>(t);
	}

	auto add_res = tr.exec1("INSERT INTO public.client (name, surname, email) "
		"VALUES('" + tr.esc(name) + "', '" + tr.esc(surname) + "', '" + tr.esc(email) + "') "
	"RETURNING id");

	tr.commit();

	refreshClients();

	return add_res[0].as<int>();
}

void ClientManager::addPhoneNumber(int clientId, const std::string& number)
{
	pqxx::work tr(*m_connecton);

	auto it = std::find_if(m_clients.begin(), m_clients.end(), [&clientId](Client& client)-> bool {
		return client.getId() == clientId;
		});

	if (it != m_clients.end()) {
		it->addNumber(tr, number);
		pqxx::work tr_r(*m_connecton);
		it->refreshData(tr_r, clientId);
	}
		
}

void ClientManager::updateClient(int clientId, const std::string& firstName, const std::string& lastName, const std::string& email)
{
	pqxx::work tr(*m_connecton);

	auto it = std::find_if(m_clients.begin(), m_clients.end(), [&clientId](Client& client)-> bool {
			return client.getId() == clientId;
		});

	if (it != m_clients.end()) {
		it->updateData(tr, firstName, lastName, email);
		pqxx::work tr_r(*m_connecton);
		it->refreshData(tr_r, clientId);
	}
		
}

void ClientManager::deletePhoneNumber(int clientId, const std::string& numberToDelete){	
	pqxx::work tr(*m_connecton);

	auto client_it = std::find_if(m_clients.begin(), m_clients.end(), [&clientId](Client& client)-> bool {
		return client.getId() == clientId;
		});

	if (client_it != m_clients.end()) {
		auto numbers = client_it->getNumbers();

		auto found_num = std::find_if(numbers.begin(), numbers.end(), [&numberToDelete](std::tuple<int, std::string> number) ->bool {
			return std::get<1>(number) == numberToDelete;
			});

		if (found_num != numbers.end()) {
			client_it->deleteNumber(tr, std::get<0>(*found_num));
			pqxx::work tr_r(*m_connecton);
			client_it->refreshData(tr_r, clientId);
		}
			
	}
}

void ClientManager::removeClient(int clientId)
{
	pqxx::work tr(*m_connecton);

	auto client_it = std::find_if(m_clients.begin(), m_clients.end(), [&clientId](Client& client)-> bool {
		return client.getId() == clientId;
		});

	if (client_it != m_clients.end()) {
		client_it->deleteItself(tr);

		m_clients.erase(client_it);
	}
}

std::vector<std::tuple<int, std::string, std::string, std::string>> ClientManager::findClients(const std::string& searchValue)
{
	std::vector<std::tuple<int, std::string, std::string, std::string>> ret;

	for (auto it = m_clients.begin(); it != m_clients.end(); std::advance(it, 1)) {
		if (it->getEmail() == searchValue || it->getName() == searchValue || it->getSurname() == searchValue) {
			ret.emplace_back(it->getId(), it->getName(), it->getSurname(), it->getEmail());
			continue;
		}
			
		auto numbers = it->getNumbers();

		for (const auto number : numbers) {
			if (std::get<1>(number) == searchValue) {
				ret.emplace_back(it->getId(), it->getName(), it->getSurname(), it->getEmail());
				break;
			}
		}
	}

	return ret;
}

std::vector<std::tuple<int, std::string, std::string, std::string>> ClientManager::getAllClients()
{
	std::vector<std::tuple<int, std::string, std::string, std::string>> ret;

	for (auto client : m_clients)
		ret.emplace_back(client.getId(), client.getName(), client.getSurname(), client.getEmail());

	return ret;
}

std::vector<std::tuple<int, std::string>> ClientManager::getPhoneNumbers(int clientId)
{
	auto client_it = std::find_if(m_clients.begin(), m_clients.end(), [&clientId](Client& client)-> bool {
		return client.getId() == clientId;
		});

	if (client_it != m_clients.end()) {
		return client_it->getNumbers();
	}

	std::exception ex{ "Client not found!" };
	throw ex;
}