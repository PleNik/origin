#include<iostream>
#include<wt/dbo/dbo.h>
#include<Wt/Dbo/backend/Postgres.h>
#include<Windows.h>

#pragma execution_character_set("utf-8")

class Book;
class Stock;
class Shop;
class Sale;

class Publisher {
public:
	std::string name;
	Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books;

	template<typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
	}

};

class Book {
public:
	std::string title;
	Wt::Dbo::ptr<Publisher> publisher;


	template<typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, title, "title");
		Wt::Dbo::belongsTo(a, publisher, "publisher");
	}
};

class Stock {
public:
	int count{};
	Wt::Dbo::ptr<Shop> shops;
	Wt::Dbo::ptr<Book> books;

	template<typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::belongsTo(a, shops, "shop");
		Wt::Dbo::belongsTo(a, books, "book");
	}
};

class Shop {
public:
	std::string name;
	Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

	template<typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
	}
};

class Sale {
public:
	double price{};
	std::string data_sale;
	int count{};
	Wt::Dbo::ptr<Stock> stocks;

	template<typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, price, "price");
		Wt::Dbo::field(a, data_sale, "data_sale");
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::belongsTo(a, stocks, "stock");
	}
};

int main() {

	//setlocale(LC_ALL, "ru");

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	setvbuf(stdout, nullptr, _IOFBF, 1000);

	try {
		std::string connectionString =
			"host=localhost "
			"port=5432 "
			"dbname=Books "
			"user=postgres "
			"password=L29samolet";

		std::unique_ptr<Wt::Dbo::backend::Postgres> connection = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);

		Wt::Dbo::Session s;
		s.setConnection(move(connection));

		s.mapClass<Publisher>("publisher");
		s.mapClass<Book>("book");
		s.mapClass<Shop>("shop");
		s.mapClass<Stock>("stock");
		s.mapClass<Sale>("sale");

		s.createTables();


	}
	catch (const std::exception& e) {
		std::cout << "Exception happened " << e.what() << std::endl;
	}
}