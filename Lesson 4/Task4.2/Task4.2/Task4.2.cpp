#include <iostream>
#include<string>
#include<fstream>

class Address {
    std::string city;
    std::string street;
    int houseNumber = 0;
    int apartamentNumber = 0;

public:
    Address(std::string& city, std::string& street, int houseNumber, int apartamentNumber)
    {
        this->city = city;
        this->street = street;
        this->houseNumber = houseNumber;
        this->apartamentNumber = apartamentNumber;
    }

    Address() {}

    std::string outputFile()
    {
        return this->city + ", " + this->street + ", " + std::to_string(this->houseNumber) + ", " + std::to_string(this->apartamentNumber);

    }

    void setCity(std::string& city) {
        this->city = city;
    };

    void setStreet(std::string& street) {
        this->street = street;
    };

    void setHouseNumber(int houseNomber) {
        this->houseNumber = houseNomber;
    };

    void setApartamentNumber(int apartamentNumber) {
        this->apartamentNumber = apartamentNumber;
    };

    std::string getCity() {
        return city;
    }

    std::string getStreet() {
        return street;
    }

    int getHouseNumber() {
        return houseNumber;
    }

    int getApartamentNumber() {
        return apartamentNumber;
    }


};

Address* createArrayOFAddress(int size); //функция создания динамического массива
void deleteArray(Address* arr); //функция очистки выделеной под массивы памяти
void sort(Address* arr, int size); //функциия сортировки массива

int main(){
    int sizeArr = 0;

    std::string path_in = "in.txt";
    std::string path_out = "out.txt";

    std::string str; //буферная переменная для считывания данных из файла

    std::ifstream fin(path_in);

    //считываение из файла размера массива
    if (fin.is_open()) {
        fin >> str;
        sizeArr = std::stoi(str); //размер массива

        fin.close();
    }
    else
        std::cout << "Error opening file!" << std::endl;

    //создание динмаического массива
    Address* arrayOFAddress = createArrayOFAddress(sizeArr);

    //временные переменные для хранения полей адреса
    std::string city, street;
    int houseNumber, apartamentNumber;

    //считывание из файла массива
    fin.open(path_in);

    if (fin.is_open()) {

        fin >> str;

        for (int i = 0; i < sizeArr; i++) {
            fin >> city;
            fin >> street;
            fin >> houseNumber;
            fin >> apartamentNumber;

            Address address(city, street, houseNumber, apartamentNumber);
            arrayOFAddress[i] = address;
        }

        fin.close();
    }
    else
        std::cout << "Error opening file!" << std::endl;

    //сортировка массива
    sort(arrayOFAddress, sizeArr);

    //запись в файл
    std::ofstream fout(path_out);

    if (fout.is_open()) {
        fout << sizeArr << std::endl;

        for (int i = 0; i < sizeArr; i++) {

            fout << arrayOFAddress[i].outputFile() << std::endl;
        }
        fout.close();
    }
    else
        std::cout << "Error opening file!" << std::endl;

    //очистка памяти
    deleteArray(arrayOFAddress);

    return 0;
}

Address* createArrayOFAddress(int size) {
    Address* arr = new Address[size];

    return arr;
}

void deleteArray(Address* arr) {
    delete[] arr;
}

void sort(Address* arr, int size)
{
    for (int i = 0; i < size; i++) {

        for (int j = 1; j < size - i; j++) {

            if (arr[j - 1].getCity() > arr[j].getCity())
            {
                std::string tempCityStreet1 = arr[j].getCity();
                std::string tempCityStreet2 = arr[j - 1].getCity();
                arr[j].setCity(tempCityStreet2);
                arr[j - 1].setCity(tempCityStreet1);

                tempCityStreet1 = arr[j].getStreet();
                tempCityStreet2 = arr[j - 1].getStreet();
                arr[j].setStreet(tempCityStreet2);
                arr[j - 1].setStreet(tempCityStreet1);

                int tempHouseAppartNumber1 = arr[j].getHouseNumber();
                int tempHouseAppartNumber2 = arr[j - 1].getHouseNumber();
                arr[j].setHouseNumber(tempHouseAppartNumber2);
                arr[j - 1].setHouseNumber(tempHouseAppartNumber1);

                tempHouseAppartNumber1 = arr[j].getApartamentNumber();
                tempHouseAppartNumber2 = arr[j - 1].getApartamentNumber();
                arr[j].setApartamentNumber(tempHouseAppartNumber2);
                arr[j - 1].setApartamentNumber(tempHouseAppartNumber1);

            }

        }
    }
}
