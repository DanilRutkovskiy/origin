#pragma once
#include "sql_query_builder.hpp"

class SqlQueryBuilderAnc : public SqlSelectQueryBuilder {
public:
	SqlQueryBuilderAnc& AddWhere(const std::string& where, const std::string& key, Symvol sym);

protected:
	void add_wheres(std::string& str) override;

protected:
	std::map<int, Symvol> m_wheres_symbols;
};