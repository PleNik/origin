#include "sql_query_builder.h"

SqlSelectQueryBuilder::SqlSelectQueryBuilder() {
    std::string strConnnection = "host = 127.0.0.1 "
        "port = 5432 "
        "dbname = DbPersons "
        "user = postgres "
        "password = postgres";

	c = std::make_shared<pqxx::connection>(strConnnection);
    data.table_name = "Person";
    pqxx::transaction t{ *c };
    std::string create_table = "CREATE TABLE IF NOT EXISTS " + data.table_name + " (person_id SERIAL NOT NULL, PRIMARY KEY(person_id)); ";
    t.exec(create_table);
    t.commit();
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::SelectAll() {

    std::string find_all = "SELECT * FROM " + data.table_name + "; ";

    pqxx::transaction t{ *c };

    auto values = t.query<std::string>(find_all);

    for (std::tuple<std::string> value : values) {

        std::cout << std::get<0>(value) << std::endl;
    }

    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(std::string name_of_column) {
    pqxx::transaction t{ *c };
    
    std::string add_column = "ALTER TABLE " + data.table_name + " ADD IF NOT EXISTS " + t.esc(name_of_column) + " CHARACTER VARYING(20) NULL; ";

    t.exec(add_column);
    t.commit();
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(std::string new_table_name) {
    pqxx::transaction t{ *c };

    std::string rename_table = "ALTER TABLE " + data.table_name + " RENAME TO " + t.esc(new_table_name) + "; ";
    
    t.exec(rename_table);
    t.commit();

    data.table_name = new_table_name;

    return *this;
}

void SqlSelectQueryBuilder::AddPerson(std::string name, std::string phone) {
    pqxx::transaction t{ *c };

    std::string add_person = "INSERT INTO " + data.table_name + " (name, phone) Values('" + t.esc(name) + "', '" + t.esc(phone) + "')";
    t.exec(add_person);
    t.commit();
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(std::string id_name, std::string number_name) {

    std::string find_person;

    if (id_name == "id") {
        find_person = "SELECT name, phone FROM " + data.table_name + " WHERE person_id = '" + number_name + "';";
    }
    else {
        find_person = "SELECT name, phone FROM " + data.table_name + " WHERE name = '" + number_name + "';";
    }
    
    pqxx::transaction t{ *c };

    auto values = t.query<std::string, std::string>(find_person);

    for (std::tuple<std::string, std::string> value : values) {
        
        std::cout << std::get<0>(value) << " has phone " << std::get<1>(value) << std::endl;
    }
    
    return *this;
}


bool SqlSelectQueryBuilder::BuildQuery() const{
   std::string find_person = "SELECT person_id FROM " + data.table_name + " WHERE person_id = 42;";

   pqxx::transaction t{ *c };

   std::string id = t.query_value<std::string>("SELECT person_id FROM " + data.table_name + " WHERE person_id = 42");

   if (std::stoi(id) == 42)
       return true;
   else
       return false;
}