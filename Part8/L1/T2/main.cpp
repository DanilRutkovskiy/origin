#include <iostream>
#include "SqlQueryBuilder/sql_query_builder.hpp"

int main() {
	SqlSelectQueryBuilder builder;
	builder.AddColumn("name").AddColumn("surname");
	builder.AddFrom("students");
	builder.AddWhere("age", "42").AddWhere("score", "4");
	builder.AddWhere({ {"height", "170"}, {"iq", "150"} });
	builder.AddColumns({"sex", "height"});

	std::cout << builder.BuildQuery();
}