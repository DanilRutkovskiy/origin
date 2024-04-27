#pragma once

#include <pqxx/pqxx>
#include <memory>

class Client {
public:
	Client(pqxx::work& tr, int clientId);
	Client(const Client& cl);
	Client(Client&& cl) noexcept;
	void operator=(const Client& client);
	void operator=(Client&& client) noexcept;
public:
	int getId() const;
	std::string getName() const;
	std::string getSurname() const;
	std::string getEmail() const;
	std::vector<std::tuple<int, std::string>> getNumbers() const;

public:
	void updateData(pqxx::work& tr, const std::string& name, const std::string& surname, const std::string& email);
	void addNumber(pqxx::work& tr, const std::string& number);
	void deleteNumber(pqxx::work& tr, int numberId);
	void deleteItself(pqxx::work& tr);

public:
	void refreshData(pqxx::work& tr, int clientId);

private:
	std::tuple<int, std::string, std::string, std::string> m_data;
	std::vector<std::tuple<int, std::string>> m_numbers;
};

class ClientManager {
public:
	ClientManager();
	~ClientManager();

public:
	void initDbStrucuture();
	void refreshClients();
	int addClient(const std::string& name, const std::string& surname, const std::string& email);
	void addPhoneNumber(int clientId, const std::string& number);
	void updateClient(int clientId, const std::string& firstName, const std::string& lastName, const std::string& email);
	void deletePhoneNumber(int clientId, const std::string& numberToDelete);
	void removeClient(int clientId);
	std::vector<std::tuple<int, std::string, std::string, std::string>> findClients(const std::string& searchValue);
	std::vector<std::tuple<int, std::string, std::string, std::string>> getAllClients();
	std::vector<std::tuple<int, std::string>> getPhoneNumbers(int clientId);

private:
	std::unique_ptr<pqxx::connection> m_connecton;

	std::vector<Client> m_clients;
};