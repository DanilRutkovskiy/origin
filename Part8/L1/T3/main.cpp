#include <iostream>
#include "SqlQueryBuilder/sql_query_builder_anc.hpp"

int main() {
	SqlQueryBuilderAnc builder;
	builder.AddColumn("name").AddColumn("surname");
	builder.AddFrom("students");
	builder.SqlSelectQueryBuilder::AddWhere("age", "42").AddWhere("score", "4");
	builder.AddWhere("id", "50", Symvol::Less);
	builder.AddWheres({ {"height", "170"}, {"iq", "150"} });
	builder.AddColumns({"sex", "height"});

	std::cout << builder.BuildQuery();
}