#include <iostream>
#include "SqlQueryBuilder/sql_query_builder.hpp"

int main() {
	SqlSelectQueryBuilder builder;
	builder.AddColumn("name").AddColumn("surname");
	builder.AddFrom("students");
	builder.AddWhere("age", "42").AddWhere("score", "4");

	std::cout << builder.BuildQuery();
}