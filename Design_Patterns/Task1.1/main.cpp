#include<Windows.h>

#include "sql_query_builder.h"

#pragma execution_character_set("utf-8")

int main() {

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	setvbuf(stdout, nullptr, _IOFBF, 1000);

	try {


		SqlSelectQueryBuilder query_builder;

		//query_builder.AddColumn("first_name").AddColumn();

		query_builder.AddFrom("students");

		query_builder.AddWhere("id", "1").AddWhere("name", "Helen");

		assert(query_builder.BuildQuery(), "SELECT name, phone FROM students WHERE id=7 AND name=John;");

	}
	catch (const std::exception& e) {
		std::cout << "Error hapened: " << e.what() << std::endl;
	}
	

	return 0;
}