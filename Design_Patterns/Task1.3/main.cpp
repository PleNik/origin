#include<Windows.h>

#include "sql_query_builder.h"

#pragma execution_character_set("utf-8")

int main() {

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	setvbuf(stdout, nullptr, _IOFBF, 1000);

	try {


		AdvancedSqlSelectQueryBuilder query_builder;

		std::vector<std::string> query_vector = { "student_id", "last_name", "score"};
		query_builder.AddColumn(query_vector);

		query_builder.AddFrom("students");

		std::map<std::string, Operators> query_map;
		query_map["id"] = { "3","9" };
		
		query_builder.AddWhere1(query_map);

		assert(query_builder.BuildQuery(), "SELECT name, phone FROM students WHERE id=7 AND name=John;");

	}
	catch (const std::exception& e) {
		std::cout << "Error hapened: " << e.what() << std::endl;
	}
	

	return 0;
}