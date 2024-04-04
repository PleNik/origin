#include<iostream>
#include<exception>

class ArrayOverflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Количество элементов больше количества элментов, под которое выделена память";
    }
};

class IndexIncorrectException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Индекс выходит за пределы массива";
    }
};

class smart_array {
public:
    smart_array(int size) : size(size), data(new int[size]) {
        index = 0;
    }

    void add_element(int value) {
        if (index >= size) {
            throw ArrayOverflowException();
        }
        data[index] = value;
        index++;
    }

    int get_element(unsigned index) {

        if (index >= size) {
            throw IndexIncorrectException();
        }
        else {
            return data[index];
        }
    }

    ~smart_array() {
        delete[] data;
    }

private:
    int size;
    int* data;
    unsigned index;
};

int main() {
    setlocale(LC_ALL, "ru");
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(15);
        arr.add_element(66);
        //arr.add_element(12); //вызывает исключение

        //std::cout << arr.get_element(7) << std::endl; //вызывает исключение
        std::cout << arr.get_element(4) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}