#pragma once
#include <string>
#include <vector>
#include <tuple>

class SqlSelectQueryBuilder {
public:
	std::string BuildQuery();

	SqlSelectQueryBuilder& AddColumn(const std::string& col);
	SqlSelectQueryBuilder& AddFrom(const std::string& from);
	SqlSelectQueryBuilder& AddWhere(const std::string& where, const std::string& key);

private:
	std::string m_query;
	std::vector<std::string> m_froms;
	std::vector<std::string> m_columns;
	std::vector<std::tuple<std::string, std::string>> m_wheres;
};