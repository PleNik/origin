#include<iostream>
#include<pqxx/pqxx>
#include<fstream>
#include<Windows.h>
#include<memory>

#pragma execution_character_set("utf-8")

class DbManagement {
public:
    DbManagement(const std::string& str_connection) {
        c = std::make_shared<pqxx::connection>(str_connection);
    }

    void createTables(const std::string& str) {
        pqxx::transaction t{ *c };
        t.exec(str);
        t.commit();
    }

    void insert_into_table(const std::string& str) {
        pqxx::transaction t{ *c };
        t.exec(str);
        t.commit();
    }

    void update_data(const std::string& str) {
        pqxx::transaction t{ *c };
        t.exec(str);
        t.commit();
    }

    void delete_phone(const std::string& str) {
        pqxx::transaction t{ *c };
        t.exec(str);
        t.commit();
    }

    void delete_client(const std::string& str) {
        pqxx::transaction t{ *c };
        t.exec(str);
        t.commit();
    }

    void select_data(const std::string& str) {
        pqxx::transaction t{ *c };
        auto values = t.query<std::string, std::string, std::string, std::string>(str);

        std::cout << "First name      Last name     e-mail              Number Phone" << std::endl;
        for (auto [first_name, last_name, email, number_phone] : values) {
            std::cout << first_name << "            " << last_name << "        " << email << "          " << number_phone << std::endl;
        }
        std::cout << std::endl;
    }

private:
    std::shared_ptr <pqxx::connection> c;
};


int main() {

    // setlocale(LC_ALL, "ru");

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    setvbuf(stdout, nullptr, _IOFBF, 1000);


    try {



        std::string strConnnection = "host = 127.0.0.1 "
            "port = 5432 "
            "dbname = Clients "
            "user = postgres "
            "password = postgres";

        DbManagement client(strConnnection);

        std::string create_table_client = "CREATE TABLE IF NOT EXISTS Client("
            "client_id SERIAL NOT NULL, "
            "first_name VARCHAR(60) NOT NULL, "
            "last_name VARCHAR(60) NOT NULL, "
            "email VARCHAR(40) NOT NULL, "
            "PRIMARY KEY (client_id));";
        client.createTables(create_table_client);

        std::string create_table_phone = "CREATE TABLE IF NOT EXISTS Phone("
            "client_id INTEGER NOT NULL, "
            "number_phone VARCHAR(64) NOT NULL, "
            "PRIMARY KEY (client_id, number_phone), "
            "FOREIGN KEY (client_id) "
            "REFERENCES Client(client_id) "
            "ON DELETE CASCADE);";
        client.createTables(create_table_phone);

        std::string insert_client = "INSERT INTO client (first_name, last_name, email) Values('Петр', 'Петров', 'pp@mail.su'), ('Иван', 'Иванов', 'iv_iv@gmail.com'), "
            "('Василий', 'Васечкин', 'vas@ymail.bis')";
        client.insert_into_table(insert_client);

        std::string insert_phone = "INSERT INTO phone (client_id, number_phone) Values(1, '456-12-64'), (2, '345-65-13'), (2, '56-11-54'), (3, '935-65-34-87')";
        client.insert_into_table(insert_phone);

        std::string update_data = "UPDATE client SET first_name = 'Василий' WHERE client_id = 1;";
        client.update_data(update_data);

        std::string delete_phone = "DELETE FROM phone WHERE client_id = 2;";
        client.delete_phone(delete_phone);

        std::string delete_client = "DELETE FROM client WHERE client_id = 1;";
        client.delete_client(delete_client);

        std::cout << "Введите имя клиента: ";
        std::string name_client;
        std::cin >> name_client;

        std::string select_data = "SELECT c.first_name, c.last_name, c.email, ph.number_phone"
            " FROM client c"
            " JOIN phone ph ON c.client_id = ph.client_id"
            " WHERE c.first_name = '" + name_client + "';"; //здесь почему-то name_client оказывается пустым


        client.select_data(select_data);

        std::cout << "Hello!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error hapened: " << e.what() << std::endl;
    }

    return 0;
}