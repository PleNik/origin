#include <iostream>
#include<vector>

template<class T>
void squaring(T& a) {
    a *= a;
}

template<class T>
void squaring(std::vector<T>& v) {
    for (auto& i : v) {
        i *= i;
    }
}
template<class T>
void print(std::vector<T>& v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it < (v.end() - 1))
            std::cout << *it << ", ";
        else std::cout << *it;
    }
    std::cout << std::endl;
}

int main() {
    int x = 4;
    std::cout << "[IN]: " << x << std::endl;
    squaring(x);
    std::cout << "[OUT]: " << x << std::endl;

    std::vector<int> vect1 {-1, 4, 8};
    std::cout << "[IN]: ";
    print(vect1);

    squaring(vect1);
    std::cout << "[OUT]: ";
    print(vect1);

    std::vector<double> vect2{ -1.4, 4.6, 8.3 };
    std::cout << "[IN]: ";
    print(vect2);

    squaring(vect2);
    std::cout << "[OUT]: ";
    print(vect2);

}