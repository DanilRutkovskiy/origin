#include <iostream>
#include <fstream>
#include <exception>
#include "IniParser.hpp"

IniParser::IniParser(std::string path) : m_path{ path }
{	
	read_file(path);
}

void IniParser::add_section(const std::string& name)
{
	auto it = m_sections.find(name);

	if (it == m_sections.end()) {
		m_sections.emplace(name, name);
	}
}

void IniParser::read_file(const std::string& path)
{

	m_sections.clear();
	std::ifstream file{ path };

	std::string last_section{ "" };

	int line_ind = 0;

	if (!file.is_open()) {
		std::ios_base::failure ex{ "Can't open file \"" + path + "\""};
		throw ex;
	}
	else {
		while (!file.eof()) {
			line_ind++;
			std::string str;
			std::getline(file, str);
			format_str(str, line_ind);

			std::string section = get_section_name(str);
			if (section != "") {
				add_section(section);
				last_section = section;
				continue;
			}

			auto var = get_variable(str);
			if (var.first != "") {
				auto it = m_sections.find(last_section);
				if (it == m_sections.end()) {
					std::invalid_argument ex{ "Wrong file format. Variable initialization before section initialization" };
					throw ex;
				}

				it->second.add_node(var.second, var.first);;
			}
		}
	}

	file.close();
}

void IniParser::format_str(std::string& str, int line_num)
{
	int comment_ind = str.find(';');

	if (comment_ind == 0) {
		str = "";
		return;
	}

	if (comment_ind != -1)
		str = str.substr(0, comment_ind - 1);

	std::string temp{ "" };

	bool eqv = false;
	bool l_b = false;
	bool r_b = false;

	for (int i = 0; i < str.length(); i++) {
		if ((str[i] != ' ' && str[i] != '\t') || (l_b && !r_b)) {
			temp += str[i];

			if (eqv && !l_b) {
				temp += str.substr(i + 1, str.length() - 1);
				break;
			}

			if (l_b && r_b) {
				break;
			}

		}

		if (str[i] == '=') {
			if (eqv) {
				std::invalid_argument ex{ "Syntax error. Two = in one line. Line: " + line_num };
				throw ex;
			}

			eqv = true;
		}
		else if (str[i] == '[') {
			l_b = true;

			if (r_b) {
				std::invalid_argument ex{ "Syntax error. ] before [. Line: " + line_num};
				throw ex;
			}
		}
		else if (str[i] == ']') {
			r_b = true;

			if (eqv) {
				std::invalid_argument ex{ "Syntax error. Two = in one line. Line: " + line_num };
				throw ex;
			}
		}
	}

	str = temp;
}

std::string IniParser::get_section_name(const std::string& str)
{
	int l_b = str.find('[');
	int r_b = str.find(']');

	if (l_b == -1 || r_b == -1 || r_b < l_b)
		return "";

	return str.substr(l_b + 1, r_b - 1);
}

std::pair<std::string, std::string> IniParser::get_variable(const std::string& str)
{
	int eqv_ind = str.find('=');

	if (eqv_ind < 0) {
		return { "", "" };
	}

	std::string name = str.substr(0, eqv_ind);
	std::string val = str.substr(eqv_ind + 1, str.length());

	return { name, val };
}

Section::Section() : m_name {""}
{
}

Section::Section(const std::string& name) : m_name{ name }
{
}

void Section::add_node(Node node,const std::string& name)
{
	m_nodes[name] = node;
}

Node Section::get_node(const std::string& name)
{
	auto it = m_nodes.find(name);

	if (it != m_nodes.end())
		return it->second;
	else {
		std::string list_of_variables;
		for (const auto& el : m_nodes) {
			list_of_variables += el.first + " ";
		}
		
		std::invalid_argument ex{"Section \"" + m_name + "\" doesn't have variable \"" + name + "\"" + "\nVariables in this section: " + list_of_variables};
		throw ex;
	}
}

Node::Node() : m_val{ "" }
{
}

Node::Node(const std::string& val) : m_val { val }
{
}

Node::Node(const Node& n)
{
	m_val = n.m_val;
}

Node::Node(Node&& n) noexcept
{
	m_val = std::move(n.m_val);
}

std::string Node::get_value()
{
	return m_val;
}

void Node::operator=(const Node& n)
{
	m_val = n.m_val;
}

void Node::operator=(Node&& n) noexcept
{
	m_val = std::move(n.m_val);
}