#include "sql_query_builder.hpp"

std::string SqlSelectQueryBuilder::BuildQuery()
{
	std::string ret;

	ret += "SELECT ";
	if (m_columns.empty())
		ret += "* ";
	else {
		for (int i = 0; i < m_columns.size(); i++)
			ret += m_columns[i] + (i != m_columns.size() - 1 ? ", " : " ");
	}

	ret += "FROM ";
	if (m_froms.size() > 0)
		ret += m_froms[0] + " ";

	if (m_wheres.size() > 0) {
		ret += "WHERE ";
		for (int i = 0; i < m_wheres.size(); i++) {
			auto str = std::get<0>(m_wheres[i]);
			auto key = std::get<1>(m_wheres[i]);
			ret += str + " = " + key + (i != m_columns.size() - 1 ? " AND " : " ");
		}
	}

	ret += ";";

	return ret;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& col)
{
	m_columns.push_back(col);

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
