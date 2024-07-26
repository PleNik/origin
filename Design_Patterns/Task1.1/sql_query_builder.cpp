#include "sql_query_builder.h"

SqlSelectQueryBuilder::SqlSelectQueryBuilder() {
    std::string strConnnection = "host = 127.0.0.1 "
        "port = 5432 "
        "dbname = StudentsBuilder "
        "user = postgres "
        "password = L29samolet";

	c = std::make_shared<pqxx::connection>(strConnnection);
    table_name = "students";

    pqxx::transaction t{ *c };

    std::string create_table_students = "CREATE TABLE IF NOT EXISTS Students("
            "student_id SERIAL NOT NULL, "
            "first_name VARCHAR(60) NOT NULL, "
            "last_name VARCHAR(60) NOT NULL, "
            "score INTEGER NULL, "
            "email VARCHAR(40) NOT NULL, "
        "PRIMARY KEY (student_id));";
    t.exec(create_table_students);

    std::string create_table_phone = "CREATE TABLE IF NOT EXISTS Phone("
        "student_id INTEGER NOT NULL, "
        "number_phone VARCHAR(64) NOT NULL, "
        "PRIMARY KEY (student_id, number_phone), "
        "FOREIGN KEY (student_id) "
        "REFERENCES Students(student_id) "
        "ON DELETE CASCADE);";
    t.exec(create_table_phone);

    t.commit();
}


SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(std::string column_name) {

    pqxx::transaction t{ *c };
    
    std::string add_column = "SELECT " + t.esc(column_name) + " FROM " + table_name + "; ";

    auto values = t.query<std::string>(add_column);

    for (std::tuple<std::string> value : values) {

        std::cout << std::get<0>(value) << std::endl;
    }
    std::cout << std::endl;
   
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn() {

    std::string find_all = "SELECT * FROM " + table_name + "; ";

    pqxx::transaction t{ *c };

    auto values = t.query<int, std::string, std::string, int, std::string>(find_all);

    for (std::tuple<int, std::string, std::string, int, std::string> value : values) {

        std::cout << std::get<0>(value) << " " << std::get<1>(value) << " " << std::get<2>(value) << " " << std::get<3>(value) << " " <<std::get<4>(value) << std::endl;
    }
    std::cout << std::endl;

    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(std::string new_table_name) {

    table_name = new_table_name;

    return *this;
}


SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(std::string id_name, std::string number_name) {

    pqxx::transaction t{ *c };

    std::string find_person;

    if (id_name == "id") {
        find_person = "SELECT first_name, last_name FROM " + table_name + " WHERE student_id = '" + t.esc(number_name) + "';";
    }
    else {
        find_person = "SELECT first_name, last_name FROM " + table_name + " WHERE first_name = '" + t.esc(number_name) + "';";
    }
    

    auto values = t.query<std::string, std::string>(find_person);

    for (std::tuple<std::string, std::string> value : values) {
        
        std::cout << std::get<0>(value) << " " << std::get<1>(value) << std::endl;
    }
    
    return *this;
}

bool SqlSelectQueryBuilder::BuildQuery() const{

   pqxx::transaction t{ *c };

   std::string id = t.query_value<std::string>("SELECT student_id FROM " + table_name + " WHERE student_id = 7;");

   if (std::stoi(id) == 7)
       return true;
   else
       return false;
}