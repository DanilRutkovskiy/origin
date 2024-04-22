#pragma once
#include <map>
#include <vector>
#include <string>

class Node;
class Section;

class IniParser {
public:
	IniParser() = delete;
	IniParser(std::string&& path);

public:
	template<typename T>
	T get_value(const std::string&, bool reread = true);

private:
	void add_section(const std::string& name);
	void read_file(const std::string& path);
	void format_str(std::string& str, int line_num);
	std::string get_section_name(const std::string& str);
	std::pair<std::string, std::string> get_variable(const std::string& str);

private:
	std::map<std::string, Section> m_sections;
	std::string m_path;
};

class Node {
public:
	Node();
	Node(const std::string& val);
	Node(const Node& n);
	Node(Node&& n) noexcept;

public:
	std::string get_value();

public:
	void operator=(const Node& n);
	void operator=(Node&& n) noexcept;

private:
	std::string m_val;
};

class Section {
public:
	Section();
	Section(const std::string& name);
	Section(const Section&) = delete;
	Section(Section&&) = delete;

public:
	void add_node(Node node, const std::string& name);
	Node get_node(const std::string& name);

private:
	std::string m_name;
	std::map<std::string,Node> m_nodes;
};

template<typename T>
T IniParser::get_value(const std::string& value, bool reread)
{
	if (reread)
		read_file(m_path);

	int dot_ind = value.find('.');
	if (dot_ind <= 0) {
		std::invalid_argument ex{ "Value format doesn't match \"section.variable\" format" };
		throw ex;
	}

 	std::string sec = value.substr(0, dot_ind);
	std::string var = value.substr(dot_ind + 1, value.length() - 1);

	auto section = m_sections.find(sec);
	if (section == m_sections.end()) {
		std::invalid_argument ex{"Section \"" + sec + "\" doesn't exist"};
		throw ex;
	}

	Node node = section->second.get_node(var);

	if constexpr (std::is_same_v<T, int>) {
		return std::stoi(node.get_value());
	}
	else if constexpr (std::is_same_v<T, double>) {
		return std::stod(node.get_value());
	}
	else if constexpr (std::is_same_v<T, std::string>) {
		return node.get_value();
	}
	else {
		return {};
	}
}