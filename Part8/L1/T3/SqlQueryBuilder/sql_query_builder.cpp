#include "sql_query_builder.hpp"
#include "sql_query_builder.hpp"
#include "sql_query_builder.hpp"
#include "sql_query_builder.hpp"

std::string SqlSelectQueryBuilder::BuildQuery()
{
	std::string ret;

	add_cols(ret);

	add_froms(ret);

	add_wheres(ret);

	ret += ";";

	return ret;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& col)
{
	m_columns.push_back(col);

	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns) noexcept
{
	for (auto& e : columns)
		m_columns.push_back(e);

	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& from)
{
	m_froms.push_back(from);

	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& where, const std::string& key)
{
	m_wheres.emplace_back(where, key);

	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWheres(const std::map<std::string, std::string>& kv) noexcept
{
	for (auto& e : kv)
		m_wheres.emplace_back(e.first, e.second);

	return *this;
}

void SqlSelectQueryBuilder::add_cols(std::string& str)
{
	str += "SELECT ";
	if (m_columns.empty())
		str += "* ";
	else {
		for (int i = 0; i < m_columns.size(); i++)
			str += m_columns[i] + (i != m_columns.size() - 1 ? ", " : " ");
	}
}

void SqlSelectQueryBuilder::add_froms(std::string& str)
{
	str += "FROM ";
	if (m_froms.size() > 0)
		str += m_froms[0] + " ";
}

void SqlSelectQueryBuilder::add_wheres(std::string& str)
{
	if (m_wheres.size() > 0) {
		str += "WHERE ";
		for (int i = 0; i < m_wheres.size(); i++) {
			auto val = std::get<0>(m_wheres[i]);
			auto key = std::get<1>(m_wheres[i]);
			str += val + " = " + key + (i != m_wheres.size() - 1 ? " AND " : " ");
		}
	}
}
