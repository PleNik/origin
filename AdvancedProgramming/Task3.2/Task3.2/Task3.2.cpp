#include<iostream>
#include<exception>

class ArrayOverflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Количество элементов больше количества элментов, под которое выделена память";
    }
};

class smart_array {
public:
    smart_array(int size) {
        this->size = size;
        this->data = new int[size];
        index = 0;
    }

    void add_element(int value) {
        if (index >= size) {
            throw ArrayOverflowException();
        }
        data[index] = value;
        index++;
    }

    int get_element(int index) {

        if (index < 0 || index >= size) {
            std::cout << "Введен некорректный индекс" << std::endl;
            return -1;
        }
        else {
            return data[index];
        }

    }

    smart_array& operator = (const smart_array& other) {
        delete[] this->data;

        this->size = other.size;
        this->index = other.index;

        this->data = new int(other.size);

        for (int i = 0; i < other.size; i++) {
            this->data[i] = other.data[i];
        }
        return *this;
    }
  
    void print_array() {
        for (int i = 0; i < this->size; i++) {
            std::cout << this->data[i] << " ";
        }
        std::cout << std::endl;
    }

    ~smart_array() {
        delete[] data;
    }

private:
    int size;
    int* data;
    int index;
};


int main() {
    setlocale(LC_ALL, "ru");


    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        
        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        std::cout << "Массив arr до копирования:" << std::endl;
        arr.print_array();

        arr = new_array;
        //arr.operator=(new_array);

        std::cout << "Массив new_arr:" << std::endl;
        new_array.print_array();

        std::cout << "Массив arr после копирования копирования:" << std::endl;
        arr.print_array();


    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }


    return 0;
}