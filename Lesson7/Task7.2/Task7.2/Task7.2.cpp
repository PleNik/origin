#include <iostream>

#define SUB(a,b) ((a)-(b))

int main() {
   
    int a = 6;
    int b = 5;
    int c = 2;

    int differ = SUB(a, b);
    std::cout << differ << std::endl;

    std::cout << differ * c << std::endl;

    int sum = b + c;
    differ = SUB(a, sum);
    std::cout << differ * c << std::endl;

    return 0;
}