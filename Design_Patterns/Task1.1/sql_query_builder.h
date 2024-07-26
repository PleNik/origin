#pragma once

#include<pqxx/pqxx>
#include<string>
#include<iostream>


class SqlSelectQueryBuilder {
public:
	SqlSelectQueryBuilder();

	SqlSelectQueryBuilder& AddColumn(std::string column_name);
	SqlSelectQueryBuilder& AddColumn();
	SqlSelectQueryBuilder& AddFrom(std::string name_of_table);

	SqlSelectQueryBuilder& AddWhere(std::string id_name, std::string number_name);

	bool BuildQuery() const;
	
private:
	std::shared_ptr <pqxx::connection> c;
	std::string table_name;
};