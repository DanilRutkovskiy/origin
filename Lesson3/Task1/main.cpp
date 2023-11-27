#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Address
{
public:
	Address();
	Address(std::string city, std::string street, int house_number, int flat_number);
	void set_city(const std::string& city) { m_city = city; }
	void set_street(const std::string& street) { m_street = street; }
	void set_house_number(int number) { m_house_number = number; }
	void set_flat_number(int number) { m_flat_number = number; }

	std::string get_city() { return m_city; }
	std::string get_street() { return m_street; }
	int get_house_number() { return m_house_number; };
	int get_flat_number() { return m_flat_number; };

private:
	std::string m_city;
	std::string m_street;
	int m_house_number;
	int m_flat_number;
};

Address::Address() :m_city{ "" }, m_street{ "" }, m_house_number{ -1 }, m_flat_number{ -1 } {};
Address::Address(std::string city, std::string street, int house_nember, int flat_number) :m_city{ city }, m_street{ street }
, m_house_number{ house_nember }, m_flat_number{ flat_number } {
}

class RW
{
public:
	RW();
	~RW();
	bool read(const std::string& path);
	bool write(const std::string& path, bool sort = false);

private:
	void sort();

private:
	std::vector<Address> m_addrs;
};

RW::RW(){
}

RW::~RW() {
}

bool RW::read(const std::string& path) {
	std::ifstream in{ path };
	if (!in.is_open()) {
		return false;
	}
	else {
		std::string temp;
		std::getline(in, temp);
		int size = std::stoi(temp);
		if (size < 0)
			return false;

		m_addrs.clear();
		m_addrs.reserve(size);
		while (!in.eof()) {
			Address addr;
			std::getline(in, temp);
			addr.set_city(temp);
			std::getline(in, temp);
			addr.set_street(temp);
			std::getline(in, temp);
			addr.set_house_number(std::stoi(temp));
			std::getline(in, temp);
			addr.set_flat_number(std::stoi(temp));
			m_addrs.push_back(addr);
		}
	}

	in.close();

	return true;
}

bool RW::write(const std::string& path, bool sort) {
	std::ofstream out{ path };
	if (!out.is_open()) {
		return false;
	}
	else {
		if (sort)
			this->sort();

		std::string temp = std::to_string(m_addrs.size()) + '\n';
		out.write(temp.c_str(), temp.length());
		for (int i = m_addrs.size() - 1; i >= 0; i--) {
			temp = m_addrs[i].get_city() + ", ";
			temp += m_addrs[i].get_street() + ", ";
			temp += std::to_string(m_addrs[i].get_house_number()) + ", ";
			temp += std::to_string(m_addrs[i].get_flat_number()) + ", " + '\n';
			out.write(temp.c_str(), temp.length());
		}
	}

	out.close();
	return true;
}

void RW::sort()
{
	std::sort(m_addrs.begin(), m_addrs.end(), [&](Address& a1, Address& a2)->bool {
		return a1.get_city() > a2.get_city();
		});
}



int main() {
	RW rw;
	if (rw.read("in.txt"))
		std::cout << "Read success" << std::endl;
	else
		std::cout << "Read failure" << std::endl;

	if (rw.write("out.txt", true))
		std::cout << "Write success";
	else
		std::cout << "Write failure" << std::endl;

  	return 0;
}