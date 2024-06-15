#include<iostream>
#include<pqxx/pqxx>
#include<Windows.h>
#include<memory>

#pragma execution_character_set("utf-8")


//���� ������ ������
enum class MethodSelectionMenu {
    CreatingDbStructure = 1,
    AddNewClient,
    AddPhone,
    ChangingClientData,
    DeletePhone,
    DeleteClient,
    FindClient,
    Exit
};

//����: ���������� ������ � ��/�����
enum class ContinueWorkingWithDbOrExit {
    ContinueWorking = 1,
    Exit
};

//������ �������
enum class DataClient {
    FirstName = 1,
    LastName,
    Email,
    Phone
};

class DbManagement {
public:
    DbManagement(const std::string& str_connection) {
        c = std::make_shared<pqxx::connection>(str_connection);
    }

    void createTables() {
        pqxx::transaction t{ *c };
        std::string create_table_client = "CREATE TABLE IF NOT EXISTS Client("
            "client_id SERIAL NOT NULL, "
            "first_name VARCHAR(60) NOT NULL, "
            "last_name VARCHAR(60) NOT NULL, "
            "email VARCHAR(40) NOT NULL, "
            "PRIMARY KEY (client_id));";
        t.exec(create_table_client);

        std::string create_table_phone = "CREATE TABLE IF NOT EXISTS Phone("
            "client_id INTEGER NOT NULL, "
            "number_phone VARCHAR(64) NOT NULL, "
            "PRIMARY KEY (client_id, number_phone), "
            "FOREIGN KEY (client_id) "
            "REFERENCES Client(client_id) "
            "ON DELETE CASCADE);";
        t.exec(create_table_phone);
        t.commit();
    }

    void add_new_client() {
        std::cout << "������� ������ �������:" << std::endl;
        std::cout << "���: ";
        std::string first_name;
        std::cin >> first_name;
        std::cout << "�������: ";
        std::string last_name;
        std::cin >> last_name;
        std::cout << "e-mail: ";
        std::string email;
        std::cin >> email;

        pqxx::transaction t{ *c };
        std::string add_client = "INSERT INTO client (first_name, last_name, email) Values('" + t.esc(first_name) + "', '" + t.esc(last_name) + "', '" + t.esc(email) + "')";
        
        t.exec(add_client);
        t.commit();
    }

    void add_phone() {

        std::cout << "������� id �������: ";
        std::string id_client;
        std::cin >> id_client;
        std::cout << "������� ����� �������� ������� � ������� ���-��-��-��: ";
        std::string number_phone;
        std::cin >> number_phone;
        
        pqxx::transaction t{ *c };
        std::string insert_phone = "INSERT INTO phone (client_id, number_phone) Values(" + t.esc(id_client) + ", '" + t.esc(number_phone) + "')";

        t.exec(insert_phone);
        t.commit();
    }

    void update_data() {
        pqxx::transaction t{ *c };
        std::string update_data;
        std::cout << "�������� ������, ������� ����� ��������:" << std::endl;
        data_client = select_data_client();

        if (data_client == DataClient::FirstName) {
            std::cout << "������� id �������, ��� �������� ����� ��������: ";
            std::string client_id;
            std::cin >> client_id;
            std::cout << "������� ����� ��� �������: ";
            std::string new_name;
            std::cin >> new_name;

            update_data = "UPDATE client SET first_name = '" + t.esc(new_name) + "' WHERE client_id = " + t.esc(client_id) + "; ";
        }
        else if (data_client == DataClient::LastName) {
            std::cout << "������� id �������, ������� �������� ����� ��������: ";
            std::string client_id;
            std::cin >> client_id;
            std::cout << "������� ����� ������� �������: ";
            std::string new_lastName;
            std::cin >> new_lastName;

            update_data = "UPDATE client SET last_name = '" + t.esc(new_lastName) + "' WHERE client_id = " + t.esc(client_id) + "; ";
        }
        else if (data_client == DataClient::Email) {
            std::cout << "������� id �������, ����� �������� ����� ��������: ";
            std::string client_id;
            std::cin >> client_id;
            std::cout << "������� ����� ����� �������: ";
            std::string new_e_mail;
            std::cin >> new_e_mail;

            update_data = "UPDATE client SET email = '" + t.esc(new_e_mail) + "' WHERE client_id = " + t.esc(client_id) + "; ";
        }
        else {
            std::cout << "������� id �������, ������� �������� ����� ��������: ";
            std::string client_id;
            std::cin >> client_id;
            std::cout << "������� ������ ������� �������: ";
            std::string old_number_phone;
            std::cin >> old_number_phone;
            std::cout << "������� ����� ������� �������: ";
            std::string new_number_phone;
            std::cin >> new_number_phone;

            update_data = "UPDATE phone SET number_phone = '" + t.esc(new_number_phone) + "' WHERE client_id = " + t.esc(client_id) + " AND number_phone = '" + t.esc(old_number_phone) + "'; ";
        }

        t.exec(update_data);
        t.commit();
    }

    void delete_phone() {
        std::cout << "������� id �������, ������� �������� ����� �������: ";
        std::string client_id;
        std::cin >> client_id;
        std::cout << "������� ����� ��������, ������� ����� �������: ";
        std::string number_phone;
        std::cin >> number_phone;

        std::string delete_phone = "DELETE FROM phone WHERE client_id = " + client_id + " AND number_phone = '" + number_phone + "'; ";

        pqxx::transaction t{ *c };
        t.exec(delete_phone);
        t.commit();
    }

    void delete_client() {
        std::cout << "������� id �������, �������� ����� �������: ";
        std::string client_id;
        std::cin >> client_id;

        std::string delete_client = "DELETE FROM client WHERE client_id = " + client_id + "; ";

        pqxx::transaction t{ *c };
        t.exec(delete_client);
        t.commit();
    }

    void find_client() {
        std::string findClient;
        std::cout << "�������� ������, �� ������� ����� ����� �������:" << std::endl;
        data_client = select_data_client();

        if (data_client == DataClient::FirstName) {
            std::cout << "������� ���, �� �������� ����� ����� �������: ";
            std::string first_name;
            std::cin >> first_name;

            findClient = "SELECT c.first_name, c.last_name, c.email, "
                            "CASE WHEN p.number_phone IS NULL THEN 'not phone' "
                            "ELSE p.number_phone "
                            "END "
                "FROM client c LEFT JOIN phone p ON c.client_id = p.client_id WHERE c.first_name = '" + first_name + "'; ";
        }
    
        else if (data_client == DataClient::LastName) {
            std::cout << "������� �������, �� ������� ����� ����� �������: ";
            std::string last_name;
            std::cin >> last_name;

            findClient = "SELECT c.first_name, c.last_name, c.email, "
                "CASE WHEN p.number_phone IS NULL THEN 'not phone' "
                "ELSE p.number_phone "
                "END "
                "FROM client c LEFT JOIN phone p ON c.client_id = p.client_id WHERE c.last_name = '" + last_name + "'; ";
        }
        else if (data_client == DataClient::Email) {
            std::cout << "������� e-mail �� �������� ����� ����� �������: ";
            std::string e_mail;
            std::cin >> e_mail;

            findClient = "SELECT c.first_name, c.last_name, c.email, "
                "CASE WHEN p.number_phone IS NULL THEN 'not phone' "
                "ELSE p.number_phone "
                "END "
                "FROM client c LEFT JOIN phone p ON c.client_id = p.client_id WHERE c.email = '" + e_mail + "'; ";
        }
        else {
            std::cout << "������� �������, �� �������� ����� ����� �������: ";
            std::string number_phone;
            std::cin >> number_phone;

            findClient = "SELECT c.first_name, c.last_name, c.email, number_phone "
                "FROM client c LEFT JOIN phone p ON c.client_id = p.client_id WHERE number_phone = '" + number_phone + "'; ";
        }

        pqxx::transaction t{ *c };
        auto values = t.query<std::string, std::string, std::string, std::string>(findClient);

        for (std::tuple<std::string, std::string, std::string, std::string> value : values) {

            std::cout << std::get<0>(value) << " " << std::get<1>(value) << " has e-mail " << std::get<2>(value) << " and phone " << std::get<3>(value) << std::endl;
        }

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
    DataClient data_client{};

    DataClient select_data_client() {
        while (true) {
            std::cout << "1. ���" << std::endl;
            std::cout << "2. �������" << std::endl;
            std::cout << "3. e-mail" << std::endl;
            std::cout << "4. �������" << std::endl;

            std::cout << "�������� ��������: ";
            int unsigned userInput{};
            std::cin >> userInput;

            data_client = static_cast<DataClient>(userInput);

            if (data_client < DataClient::FirstName || data_client > DataClient::Phone) {
                std::cout << "�������� ����! ���������" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            else
                return data_client;
        }
    }
};

MethodSelectionMenu selectMethod() {
    while (true) {
        std::cout << "1. ������� ��������� ���� ������" << std::endl;
        std::cout << "2. �������� ������ �������" << std::endl;
        std::cout << "3. �������� ������� ��� ������������� �������" << std::endl;
        std::cout << "4. �������� ������ � �������" << std::endl;
        std::cout << "5. ������� ������� � ������������� �������" << std::endl;
        std::cout << "6. ������� ������������� �������" << std::endl;
        std::cout << "7. ����� ������� �� ��� ������" << std::endl;
        std::cout << "8. ����� �� ���������" << std::endl;

        std::cout << "�������� ����������� ��������: ";
        int unsigned userInput{};
        std::cin >> userInput;

        MethodSelectionMenu selectMenu = static_cast<MethodSelectionMenu>(userInput);

        if (selectMenu < MethodSelectionMenu::CreatingDbStructure || selectMenu > MethodSelectionMenu::Exit) {
            std::cout << "�������� ����! ���������" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else
            return selectMenu;
    }
}

ContinueWorkingWithDbOrExit MenuContinueOrExit() {
    unsigned userInput{};

    while (true) {
        std::cout << "\n1. ���������� ������ � ����� ������" << std::endl;
        std::cout << "2. ����� �� ���������" << std::endl;
        std::cout << "�������� ��������: ";
        std::cin >> userInput;

        ContinueWorkingWithDbOrExit continueWorkingWithDbOrExit = static_cast<ContinueWorkingWithDbOrExit>(userInput);

        if (continueWorkingWithDbOrExit < ContinueWorkingWithDbOrExit::ContinueWorking || continueWorkingWithDbOrExit > ContinueWorkingWithDbOrExit::Exit) {
            std::cout << "������! ������� ������������ ��������" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else
            return continueWorkingWithDbOrExit;
    }
}


int main() {

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    setvbuf(stdout, nullptr, _IOFBF, 1000);
	
    std::cout << "����� ���������� � ��������� ��� ���������� ���������!" << std::endl;
     
    try {

        std::string strConnnection = "host = 127.0.0.1 "
                                     "port = 5432 "
                                     "dbname = Clients "
                                     "user = postgres "
                                     "password = postgres";

        DbManagement client(strConnnection);

        do {
            MethodSelectionMenu methodType = selectMethod();

            switch (methodType)
            {
            case MethodSelectionMenu::CreatingDbStructure:
                client.createTables();
                break;

            case MethodSelectionMenu::AddNewClient:
                client.add_new_client();
                break;

            case MethodSelectionMenu::AddPhone:
                client.add_phone();
                break;

            case MethodSelectionMenu::ChangingClientData:
                client.update_data();

                break;
            case MethodSelectionMenu::DeletePhone:
                client.delete_phone();
                break;

            case MethodSelectionMenu::DeleteClient:
                client.delete_client();
                break;

            case MethodSelectionMenu::FindClient:
                client.find_client();
                break;

            case MethodSelectionMenu::Exit:
                break;

            }

        } while (MenuContinueOrExit() == ContinueWorkingWithDbOrExit::ContinueWorking);

   
    }
    catch (const std::exception& e) {
        std::cout << "Error hapened: " << e.what() << std::endl;
    }

	return 0;
}