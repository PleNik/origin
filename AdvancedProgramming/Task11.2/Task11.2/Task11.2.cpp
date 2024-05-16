#include <iostream>
#include<vector>
#include<sstream>

class big_integer {
public:
    big_integer() {}

    big_integer(const std::string& s) {
        str = s;
        for (int i = 0; i < s.length(); i++)
            v.push_back(s[i] - '0');
       
    }

    //конструктор копирования
    big_integer(const big_integer& from) {
        v = from.v;
    }

    //оператор присваивания
    big_integer& operator=(const big_integer& from) {
        if (v != from.v) {
            v.clear();
            v = from.v;
        }
        return *this;
    }

    //конструктор перемещающего копирования
    big_integer(big_integer&& from) {
        v = from.v;
        from.v.clear();
    }

    //оератор перемещающего присваивания
    big_integer& operator=(big_integer&& from) noexcept {
        if (v != from.v) {
            v = from.v;
            from.v.clear();
        }
        return *this;
    }

    //оператор сложения двух больших чисел
    big_integer operator +(const big_integer& other) {
        big_integer tmp;
        tmp.v[0] = std::move(this->v[0] + other.v[0]);
        return tmp;
    }

private:
    std::string str;
    std::vector<int> v;
    int value;
    
};

int main() {

    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;

 
    return 0;
}
