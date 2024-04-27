#include <iostream>

#include <Windows.h>
#include <conio.h>

#include "ClientManager.hpp"

void onAddPhoneNumberAct(ClientManager& cl, int clientId) {
	std::string number_str;
	std::cout << "Input number: ";
	std::cin >> number_str;

	cl.addPhoneNumber(clientId, number_str);
}

void onUpdateClientAct(ClientManager& cl, int clientId) {
	std::string name, surname, email;

	std::cout << "Enter client's name: ";
	std::cin >> name;

	std::cout << "Enter client's surname: ";
	std::cin >> surname;

	std::cout << "Enter client's enail: ";
	std::cin >> email;

	cl.updateClient(clientId, name, surname, email);
}

void onDeletePhoneNumberAct(ClientManager& cl, int clientId) {
	auto numbers = cl.getPhoneNumbers(clientId);

	std::cout << "Client's numbers: \n";
	int counter = 0;
	for (const auto& number : numbers) {
		counter++;
		std::cout << std::to_string(counter) << ". " << std::get<1>(number) << "\n";
	}

	std::cout << "Choose number to delete: ";
	int num;
	std::cin >> num;

	cl.deletePhoneNumber(clientId, std::get<1>(numbers[num - 1]));
}

void onChosenClientAct(ClientManager& cl, int clientId) {
	std::cout << "Choose action: \n 1.Add phone number \n 2.Update client \n 3.Delete phone number \n"
		<< "4.Delete client \n 0.Back \n";

	int action;
	std::cin >> action;

	switch (action) {
	case 1:
	{
		onAddPhoneNumberAct(cl, clientId);
		break;
	}
	case 2:
	{
		onUpdateClientAct(cl, clientId);
		break;
	}
	case 3:
	{
		onDeletePhoneNumberAct(cl, clientId);
		break;
	}
	case 4:
	{
		cl.removeClient(clientId);
		break;
	}
	case 0:
	{
		break;
	}
	}
}

void showClients(ClientManager& cl, std::vector<std::tuple<int, std::string, std::string, std::string>> clients) {
	int counter = 0;
	for (const auto& client : clients) {
		++counter;
		std::cout << std::to_string(counter) << ". " << std::get<1>(client) << " " <<
			std::get<2>(client) << ", " << std::get<3>(client) << "\n";

		auto numbers = cl.getPhoneNumbers(std::get<0>(client));
		std::cout << "\tClient's phone numbers: \n";
		int counter = 0;
		for (auto number : numbers) {
			counter++;
			std::cout << "\t" << std::to_string(counter) << ". " << std::get<1>(number) << "\n";
		}
	}
}

void onShowClientsAct(ClientManager& cl) {
	auto clients = cl.getAllClients();
	std::cout << "Currently registered clients: \n";

	if (clients.size() == 0) {
		std::cout << "No registered clients. Press any key to continue...\n\n";
		_getch();
		return;
	}

	showClients(cl, clients);

	std::cout << "Choose Client: ";
	int clientNum = -1;
	std::cin >> clientNum;

	auto it = clients.begin();
	std::advance(it, clientNum - 1);
	int clientId = std::get<0>(*it);

	onChosenClientAct(cl, clientId);
}

void onAddClientAct(ClientManager& cl) {
	std::string name, surname, email;

	std::cout << "Enter client's name: ";
	std::cin >> name;

	std::cout << "Enter client's surname: ";
	std::cin >> surname;

	std::cout << "Enter client's enail: ";
	std::cin >> email;

	cl.addClient(name, surname, email);
}

void onFindClientAct(ClientManager& cl) {
	std::cout << "Enter value to search for: ";
	std::string searchVal;
	std::cin >> searchVal;

	auto clients = cl.findClients(searchVal);

	showClients(cl, clients);

	std::cout << "Choose Client: ";
	int clientNum = -1;
	std::cin >> clientNum;

	auto it = clients.begin();
	std::advance(it, clientNum - 1);
	int clientId = std::get<0>(*it);

	onChosenClientAct(cl, clientId);
}

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	try {
		ClientManager cl;
		cl.initDbStrucuture();
		bool exec = true;
		while (exec)
		{
			std::cout << "Client database. \n Actions: \n";
			std::cout << "1 - Show clients \n 2 - Add client \n "
				"3 - Find client \n 0 - Exit \n Choose action: ";

			int act;
			std::cin >> act;

			system("CLS");

			switch (act) {
			case 0:
			{
				exec = false;
				break;
			}
			case 1:
			{
				onShowClientsAct(cl);

				break;
			}
			case 2:
			{
				onAddClientAct(cl);
				break;
			}
			case 3:
			{
				onFindClientAct(cl);
				break;
			}
			default:
				std::cout << "Wrong command!\n";
				break;
			}	
		}
	}
	catch (std::exception ex) {
		std::cout << ex.what();
	}

	return 0;
}
