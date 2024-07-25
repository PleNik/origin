#pragma once

#include<pqxx/pqxx>
#include<string>

#include"data.h"


class SqlSelectQueryBuilder {
public:
	SqlSelectQueryBuilder();

	SqlSelectQueryBuilder& SelectAll();
	SqlSelectQueryBuilder& AddColumn(std::string name_of_column);
	SqlSelectQueryBuilder& AddFrom(std::string name_of_table);

	void AddPerson(std::string name, std::string phone);
	SqlSelectQueryBuilder& AddWhere(std::string id_name, std::string number_name);

	bool BuildQuery() const;
	
private:
	std::shared_ptr <pqxx::connection> c;
	std::string table_name;
	Data data;
};