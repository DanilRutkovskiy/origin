#pragma once
#include <string>
#include <vector>
#include <tuple>
#include <map>

enum class Symvol {
	More,
	Less,
	Eqv
};

class SqlSelectQueryBuilder {
public:
	std::string BuildQuery();

	SqlSelectQueryBuilder& AddColumn(const std::string& col);
	SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;
	SqlSelectQueryBuilder& AddFrom(const std::string& from);
	SqlSelectQueryBuilder& AddWhere(const std::string& where, const std::string& key);
	SqlSelectQueryBuilder& AddWheres(const std::map<std::string, std::string>& kv) noexcept;

protected:
	void add_cols(std::string& str);
	void add_froms(std::string& str);
	virtual void add_wheres(std::string& str);

protected:
	std::vector<std::string> m_froms;
	std::vector<std::string> m_columns;
	std::vector<std::tuple<std::string, std::string>> m_wheres;
};