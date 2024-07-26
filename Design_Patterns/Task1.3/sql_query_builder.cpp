#include "sql_query_builder.h"

SqlSelectQueryBuilder::SqlSelectQueryBuilder() {
    std::string strConnnection = "host = 127.0.0.1 "
        "port = 5432 "
        "dbname = StudentsBuilder "
        "user = postgres "
        "password =postgres";

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


SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::vector<std::string>& columns) {

    pqxx::transaction t{ *c };
    
    for (const auto& el : columns) {

        std::string add_column = "SELECT " + t.esc(el) + " FROM " + table_name + "; ";

        auto values = t.query<std::string>(add_column);

        for (std::tuple<std::string> value : values) {

            std::cout << std::get<0>(value) << std::endl;
        }
        std::cout << std::endl;
    }
   
   
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


SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv)  noexcept {

    pqxx::transaction t{ *c };

    std::string find_person;

    for (auto itr{ kv.begin() }; itr != kv.end(); itr++) {
        if (itr->first == "id") {
            find_person = "SELECT first_name, last_name FROM " + table_name + " WHERE student_id = '" + t.esc(itr->second) + "';";
        }
        else {
            find_person = "SELECT first_name, last_name FROM " + table_name + " WHERE first_name = '" + t.esc(itr->second) + "';";
        }

        auto values = t.query<std::string, std::string>(find_person);

        for (std::tuple<std::string, std::string> value : values) {

            std::cout << std::get<0>(value) << " " << std::get<1>(value) << std::endl;
        }
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

AdvancedSqlSelectQueryBuilder::AdvancedSqlSelectQueryBuilder():SqlSelectQueryBuilder(){}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhere1(const std::map<std::string, Operators>& kv)noexcept {

    pqxx::transaction t{ *c };

    std::string find_person;

    for (auto itr{ kv.begin() }; itr != kv.end(); itr++) {
        find_person = "SELECT first_name, last_name FROM " + table_name + " WHERE student_id > " + t.esc(itr->second.more) + " AND student_id < '" + t.esc(itr->second.less) + "';";

       auto values = t.query<std::string, std::string>(find_person);

        for (std::tuple<std::string, std::string> value : values) {

            std::cout << std::get<0>(value) << " " << std::get<1>(value) << std::endl;
        }
    }

    return *this;
}
