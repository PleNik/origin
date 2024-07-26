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
	
protected:
	std::shared_ptr <pqxx::connection> c;
	std::string table_name;
};

struct Operators {
	std::string more;
	std::string less;
};

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder {
public:
	AdvancedSqlSelectQueryBuilder();
	AdvancedSqlSelectQueryBuilder& AddWhere1 (const std::map<std::string, Operators>& kv)  noexcept;

};