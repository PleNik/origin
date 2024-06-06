#include<iostream>
#include<wt/dbo/dbo.h>
#include<Wt/Dbo/backend/Postgres.h>
#include<Windows.h>
#include<memory>
#include<set>

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
		Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
	}

};

class Book {
public:
	std::string title;
	Wt::Dbo::ptr<Publisher> publisher;
	Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

	template<typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, title, "title");
		Wt::Dbo::belongsTo(a, publisher, "publisher");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
	}
};

class Stock {
public:
	int count{};
	Wt::Dbo::ptr<Shop> shops;
	Wt::Dbo::ptr<Book> books;
	Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> sales;

	template<typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::belongsTo(a, shops, "shop");
		Wt::Dbo::belongsTo(a, books, "book");
		Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
	}
};

class Shop {
public:
	std::string name;
	Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

	template<typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
	}
};

class Sale {
public:
	double price{};
	std::string date_sale;
	int count{};
	Wt::Dbo::ptr<Stock> stocks;

	template<typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, price, "price");
		Wt::Dbo::field(a, date_sale, "date_sale");
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::belongsTo(a, stocks, "stock");
	}
};

void FillingTables(Wt::Dbo::Session& s) {

	Wt::Dbo::Transaction tr{ s };

	//заполнение таблицы Publisher
	auto publisher1 = std::unique_ptr<Publisher>(new Publisher{ "Eksmo" });
	auto publisher2 = std::unique_ptr<Publisher>(new Publisher{ "Ast" });
	auto publisher3 = std::unique_ptr<Publisher>(new Publisher{ "Triumf" });
	auto publisher4 = std::unique_ptr<Publisher>(new Publisher{ "Azbuk-Atticus" });
	auto publisher5 = std::unique_ptr<Publisher>(new Publisher{ "Rippol-classic" });
	auto publisher6 = std::unique_ptr<Publisher>(new Publisher{ "Alpina-Publisher" });

	Wt::Dbo::ptr<Publisher>p_publisher1 = s.add<Publisher>(move(publisher1));
	Wt::Dbo::ptr<Publisher>p_publisher2 = s.add<Publisher>(move(publisher2));
	Wt::Dbo::ptr<Publisher>p_publisher3 = s.add<Publisher>(move(publisher3));
	Wt::Dbo::ptr<Publisher>p_publisher4 = s.add<Publisher>(move(publisher4));
	Wt::Dbo::ptr<Publisher>p_publisher5 = s.add<Publisher>(move(publisher5));
	Wt::Dbo::ptr<Publisher>p_publisher6 = s.add<Publisher>(move(publisher6));

	//заполнение таблицы Book
	auto book1 = std::unique_ptr<Book>(new Book{ "Everyday Life in North Korea", p_publisher6 });
	auto book2 = std::unique_ptr<Book>(new Book{ "In seven years", p_publisher3 });
	auto book3 = std::unique_ptr<Book>(new Book{ "Four quarters", p_publisher5 });
	auto book4 = std::unique_ptr<Book>(new Book{ "Children of the Dead Star", p_publisher1 });
	auto book5 = std::unique_ptr<Book>(new Book{ "This is madness", p_publisher2 });
	auto book6 = std::unique_ptr<Book>(new Book{ "Dunno is studying", p_publisher4 });
	auto book7 = std::unique_ptr<Book>(new Book{ "How Dinosaurs Died", p_publisher6 });
	auto book8 = std::unique_ptr<Book>(new Book{ "Ancient Meotida", p_publisher3 });
	auto book9 = std::unique_ptr<Book>(new Book{ "Secret Garden", p_publisher5 });
	auto book10 = std::unique_ptr<Book>(new Book{ "Smile of Dawn", p_publisher1 });
	auto book11 = std::unique_ptr<Book>(new Book{ "Master and Margarita", p_publisher2 });
	auto book12 = std::unique_ptr<Book>(new Book{ "Teacher's portfolio", p_publisher4 });

	Wt::Dbo::ptr<Book>p_book1 = s.add<Book>(move(book1));
	Wt::Dbo::ptr<Book>p_book2 = s.add<Book>(move(book2));
	Wt::Dbo::ptr<Book>p_book3 = s.add<Book>(move(book3));
	Wt::Dbo::ptr<Book>p_book4 = s.add<Book>(move(book4));
	Wt::Dbo::ptr<Book>p_book5 = s.add<Book>(move(book5));
	Wt::Dbo::ptr<Book>p_book6 = s.add<Book>(move(book6));
	Wt::Dbo::ptr<Book>p_book7 = s.add<Book>(move(book7));
	Wt::Dbo::ptr<Book>p_book8 = s.add<Book>(move(book8));
	Wt::Dbo::ptr<Book>p_book9 = s.add<Book>(move(book9));
	Wt::Dbo::ptr<Book>p_book10 = s.add<Book>(move(book10));
	Wt::Dbo::ptr<Book>p_book11 = s.add<Book>(move(book11));
	Wt::Dbo::ptr<Book>p_book12 = s.add<Book>(move(book12));

	//заполнение таблицы Shop
	auto shop1 = std::unique_ptr<Shop>(new Shop{ "Read-city" });
	auto shop2 = std::unique_ptr<Shop>(new Shop{ "Book-House" });
	auto shop3 = std::unique_ptr<Shop>(new Shop{ "Living-Word" });
	auto shop4 = std::unique_ptr<Shop>(new Shop{ "Piotrovsky" });
	auto shop5 = std::unique_ptr<Shop>(new Shop{ "Other-Dimensions" });

	Wt::Dbo::ptr<Shop>p_shop1 = s.add<Shop>(move(shop1));
	Wt::Dbo::ptr<Shop>p_shop2 = s.add<Shop>(move(shop2));
	Wt::Dbo::ptr<Shop>p_shop3 = s.add<Shop>(move(shop3));
	Wt::Dbo::ptr<Shop>p_shop4 = s.add<Shop>(move(shop4));
	Wt::Dbo::ptr<Shop>p_shop5 = s.add<Shop>(move(shop5));

	//заполнение таблицы Stock
	auto stock1 = std::unique_ptr<Stock>(new Stock{ 20,p_shop1, p_book1 });
	auto stock2 = std::unique_ptr<Stock>(new Stock{ 50,p_shop2, p_book2 });
	auto stock3 = std::unique_ptr<Stock>(new Stock{ 30,p_shop3, p_book2 });
	auto stock4 = std::unique_ptr<Stock>(new Stock{ 40,p_shop4, p_book3 });
	auto stock5 = std::unique_ptr<Stock>(new Stock{ 80,p_shop5, p_book7 });
	auto stock6 = std::unique_ptr<Stock>(new Stock{ 10,p_shop2, p_book8 });
	auto stock7 = std::unique_ptr<Stock>(new Stock{ 90,p_shop3, p_book8 });

	Wt::Dbo::ptr<Stock>p_stock1 = s.add<Stock>(move(stock1));
	Wt::Dbo::ptr<Stock>p_stock2 = s.add<Stock>(move(stock2));
	Wt::Dbo::ptr<Stock>p_stock3 = s.add<Stock>(move(stock3));
	Wt::Dbo::ptr<Stock>p_stock4 = s.add<Stock>(move(stock4));
	Wt::Dbo::ptr<Stock>p_stock5 = s.add<Stock>(move(stock5));
	Wt::Dbo::ptr<Stock>p_stock6 = s.add<Stock>(move(stock6));
	Wt::Dbo::ptr<Stock>p_stock7 = s.add<Stock>(move(stock7));

	//заполнение таблицы Sale
	auto sale1 = std::unique_ptr<Sale>(new Sale{ 256.70, "2024-05-25", 2, p_stock6 });
	auto sale2 = std::unique_ptr<Sale>(new Sale{ 124.53, "2020-12-01", 1, p_stock2 });
	auto sale3 = std::unique_ptr<Sale>(new Sale{ 471.44, "2014-08-20", 3, p_stock5 });
	auto sale4 = std::unique_ptr<Sale>(new Sale{ 325.30, "2009-07-11", 4, p_stock2 });
	auto sale5 = std::unique_ptr<Sale>(new Sale{ 511.40, "2018-06-02", 2, p_stock3 });
	auto sale6 = std::unique_ptr<Sale>(new Sale{ 731.70, "2019-09-05", 3, p_stock7 });
	auto sale7 = std::unique_ptr<Sale>(new Sale{ 1231.10, "2017-11-07", 5, p_stock6 });
	auto sale8 = std::unique_ptr<Sale>(new Sale{ 967.00, "2021-10-10", 2, p_stock1 });
	auto sale9 = std::unique_ptr<Sale>(new Sale{ 875.40, "2022-01-12", 3, p_stock4 });

	Wt::Dbo::ptr<Sale>p_sale1 = s.add<Sale>(move(sale1));
	Wt::Dbo::ptr<Sale>p_sale2 = s.add<Sale>(move(sale2));
	Wt::Dbo::ptr<Sale>p_sale3 = s.add<Sale>(move(sale3));
	Wt::Dbo::ptr<Sale>p_sale4 = s.add<Sale>(move(sale4));
	Wt::Dbo::ptr<Sale>p_sale5 = s.add<Sale>(move(sale5));
	Wt::Dbo::ptr<Sale>p_sale6 = s.add<Sale>(move(sale6));
	Wt::Dbo::ptr<Sale>p_sale7 = s.add<Sale>(move(sale7));
	Wt::Dbo::ptr<Sale>p_sale8 = s.add<Sale>(move(sale8));
	Wt::Dbo::ptr<Sale>p_sale9 = s.add<Sale>(move(sale9));

	tr.commit();
}

void Publisher_query(Wt::Dbo::Session& s) {

	Wt::Dbo::Transaction tr{ s };

	

	std::string user_input = "exit";
	do {
		std::set<std::string>shopNames;
		std::cout << "¬ведите название издательства либо exit дл€ выхода из программы: ";
		std::cin >> user_input;

		if (user_input == "exit")
			break;

		Wt::Dbo::ptr<Publisher> p = s.find<Publisher>().where("name = ?").bind(user_input);

		if (p) {

			for (const auto& book : p->books) {

				for (const auto& stock : book->stocks)
					shopNames.insert(stock->shops->name);
			}

			if (shopNames.empty())
				std::cout << "Ќет магазинов, в которых продаютс€ книги издател€ " << p->name << std::endl;
			else {
				std::cout << "ћагазины, где проадютс€ книги издател€ " << p->name<<":" << std::endl;
				for (const auto& shopName : shopNames)
					std::cout << shopName << std::endl;
			}
			
		}
		else {
			std::cout << "»здатель " << user_input << " не найден" << std::endl;
		}

		

	} while (true);

	tr.commit();
}

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


		//s.createTables(); //создание таблиц

		//FillingTables(s); //заполнение таблиц


		Publisher_query(s); //запрос магазинов, в которых продают книги введенного издател€
	

	}
	catch (const std::exception& e) {
		std::cout << "Exception happened " << e.what() << std::endl;
	}
}