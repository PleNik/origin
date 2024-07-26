#pragma once

#include<pqxx/pqxx>
#include<string>
#include<iostream>


class SqlSelectQueryBuilder {
public:
	SqlSelectQueryBuilder();

	SqlSelectQueryBuilder& AddColumn(const std::vector<std::string>& columns);
	SqlSelectQueryBuilder& AddColumn();
	SqlSelectQueryBuilder& AddFrom(std::string name_of_table);

	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;

	bool BuildQuery() const;
	
private:
	std::shared_ptr <pqxx::connection> c;
	std::string table_name;
};