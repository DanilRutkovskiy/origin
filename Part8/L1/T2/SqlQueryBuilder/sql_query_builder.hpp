#pragma once
#include <string>
#include <vector>
#include <tuple>
#include <map>

class SqlSelectQueryBuilder {
public:
	std::string BuildQuery();

	SqlSelectQueryBuilder& AddColumn(const std::string& col);
	SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;
	SqlSelectQueryBuilder& AddFrom(const std::string& from);
	SqlSelectQueryBuilder& AddWhere(const std::string& where, const std::string& key);
	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;

private:
	std::string m_query;
	std::vector<std::string> m_froms;
	std::vector<std::string> m_columns;
	std::vector<std::tuple<std::string, std::string>> m_wheres;
};