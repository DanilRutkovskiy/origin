#include "sql_query_builder_anc.hpp"
#include "sql_query_builder_anc.hpp"
#include "sql_query_builder_anc.hpp"

SqlQueryBuilderAnc& SqlQueryBuilderAnc::AddWhere(const std::string& where, const std::string& key, Symvol sym)
{
	m_wheres_symbols[m_wheres.size()] = sym;
	__super::AddWhere(where, key);
	return *this;
}

void SqlQueryBuilderAnc::add_wheres(std::string& str)
{
	if (m_wheres.size() > 0) {
		str += "WHERE ";
		for (int i = 0; i < m_wheres.size(); i++) {
			auto val = std::get<0>(m_wheres[i]);
			auto key = std::get<1>(m_wheres[i]);
			
			std::string sym;
			auto it = m_wheres_symbols.find(i);
			if (it == m_wheres_symbols.end())
				sym = "=";
			else if (it->second == Symvol::Eqv)
				sym = "=";
			else if (it->second == Symvol::Less)
				sym = "<";
			else if (it->second == Symvol::More)
				sym = ">";

			str += val + sym + key + (i != m_wheres.size() - 1 ? " AND " : " ");
		}
	}
}