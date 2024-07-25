#include<Windows.h>

#include "sql_query_builder.h"

#pragma execution_character_set("utf-8")

int main() {

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	setvbuf(stdout, nullptr, _IOFBF, 1000);

	try {


		SqlSelectQueryBuilder query_builder;

		query_builder.AddColumn("name").AddColumn("phone");
		//query_builder.SelectAll();
		query_builder.AddPerson("Uriy", "986 986 98 34");
		query_builder.AddPerson("Jackson", "333 333 33 33");
		query_builder.AddPerson("Helen", "222 222 22 22");

		query_builder.AddFrom("students");

		query_builder.AddWhere("id", "1").AddWhere("name", "Helen");

		//static_assert(query_builder.BuildQuery(), "SELECT name, phone FROM students WHERE id=42 AND name=John;");

	}
	catch (const std::exception& e) {
		std::cout << "Error hapened: " << e.what() << std::endl;
	}
	

	return 0;
}