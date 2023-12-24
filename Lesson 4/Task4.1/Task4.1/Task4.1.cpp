#include <iostream>
#include<string>
#include<fstream>

class Address {
    std::string city;
    std::string street;
    int houseNumber = 0;
    int apartamentNumber = 0;

public:
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

    //считывание из файла массива
    fin.open(path_in);

    if (fin.is_open()) {

        fin >> str;

        for (int i = 0; i < sizeArr; i++) {
            fin >> str;
            arrayOFAddress[i].setCity(str);
            fin >> str;
            arrayOFAddress[i].setStreet(str);
            fin >> str;
            arrayOFAddress[i].setHouseNumber(std::stoi(str));
            fin >> str;
            arrayOFAddress[i].setApartamentNumber(std::stoi(str));
        }

        fin.close();
    }
    else
        std::cout << "Error opening file!" << std::endl;

    //запись в файл
    std::ofstream fout(path_out);

    if (fout.is_open()) {

        fout << sizeArr << std::endl;
        for (int i = sizeArr - 1; i >= 0; i--) {
            fout << arrayOFAddress[i].getCity() << ", " << arrayOFAddress[i].getStreet() << ", "
                << arrayOFAddress[i].getHouseNumber() << ", " << arrayOFAddress[i].getApartamentNumber() << std::endl;
        }
        fout.close();
    }
    else
        std::cout << "Error opening file!" << std::endl;

    //очистка памяти
    deleteArray(arrayOFAddress);

    return 0;
}

Address* createArrayOFAddress(int size){
    Address* arr = new Address[size];

    return arr;
}

void deleteArray(Address* arr){
    delete[] arr;
}
