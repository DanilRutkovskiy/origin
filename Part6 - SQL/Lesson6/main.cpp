#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>

int main() {
	std::string connectionString;
	std::unique_ptr<Wt::Dbo::backend::Postgres> connection{ new Wt::Dbo::backend::Postgres{connectionString} };
	
	return 0;
}