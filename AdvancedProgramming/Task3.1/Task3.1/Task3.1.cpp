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

    int get_element(int index) {

        if (index < 0 || index >= size) {
            std::cout << "Введен некорректный индекс" << std::endl;
            return -1;
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
    int index;
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
        // arr.add_element(12);

        std::cout << arr.get_element(4) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }


    return 0;
}