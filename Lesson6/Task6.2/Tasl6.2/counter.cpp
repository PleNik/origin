#include "counter.h"

   void Counter:: setIncrement() {
        value++;
    };

    void Counter::setDecrement() {
        value--;
    };

    void Counter::printValue() {
        std::cout << value << std::endl;
    };

    Counter::Counter() {
        this->value = 1;
    };

    Counter::Counter(int value) {
        this->value = value;
    };

