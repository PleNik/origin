#include <iostream>
#include <thread>
#include <mutex>

class Data {
public:
    std::mutex mtx;
    int mi_value;
    double md_value;
    float mf_value;

    Data(int i_value, double d_value, float f_value) : mi_value(i_value), md_value(d_value), mf_value(f_value) {}

    int get_ivalue() { return mi_value; }
    int get_dvalue() { return md_value; }
    int get_fvalue() { return mf_value; }

    void print() {
        std::cout << "int_value = " << mi_value << std::endl;
        std::cout << "double_value = " << md_value << std::endl;
        std::cout << "float_value = " << mf_value << std::endl;
    }


};

void swapData1(Data& data1, Data& data2) {

    std::lock(data1.mtx, data2.mtx);

    std::lock_guard<std::mutex> lg1(data1.mtx, std::adopt_lock);
    std::lock_guard<std::mutex> lg2(data2.mtx, std::adopt_lock);
    

    Data temp(0, 0, 0);

    temp.mi_value = data1.mi_value;
    temp.md_value = data1.md_value;
    temp.mf_value = data1.mf_value;

    data1.mi_value = data2.mi_value;
    data1.md_value = data2.md_value;
    data1.mf_value = data2.mf_value;

    data2.mi_value = temp.mi_value;
    data2.md_value = temp.md_value;
    data2.mf_value = temp.mf_value;

  
}

void swapData2(Data& data1, Data& data2) {
    std::unique_lock<std::mutex>ul1(data1.mtx, std::defer_lock);
    std::unique_lock<std::mutex>ul2(data2.mtx, std::defer_lock);

    std::lock(ul1, ul2);

    Data temp(0, 0, 0);
    temp.mi_value = data1.mi_value;
    temp.md_value = data1.md_value;
    temp.mf_value = data1.mf_value;

    data1.mi_value = data2.mi_value;
    data1.md_value = data2.md_value;
    data1.mf_value = data2.mf_value;

    data2.mi_value = temp.mi_value;
    data2.md_value = temp.md_value;
    data2.mf_value = temp.mf_value;
}

void swapData3(Data& data1, Data& data2) {
    std::scoped_lock(data1.mtx, data2.mtx);

    Data temp(0, 0, 0);
    temp.mi_value = data1.mi_value;
    temp.md_value = data1.md_value;
    temp.mf_value = data1.mf_value;

    data1.mi_value = data2.mi_value;
    data1.md_value = data2.md_value;
    data1.mf_value = data2.mf_value;

    data2.mi_value = temp.mi_value;
    data2.md_value = temp.md_value;
    data2.mf_value = temp.mf_value;
}

int main() {

    Data data1(23, 45.12, 0.34);
    Data data2(11, 7.23, 5.23);

    std::cout << "data1 before swap: " << std::endl;
    data1.print();
    std::cout << std::endl;
    std::cout << "data2 before swap: " << std::endl;
    data2.print();

    std::cout << "========after swap============" << std::endl;


    std::thread th(swapData3, std::ref(data1), std::ref(data2));

    th.join();

    std::cout << "data1 after swap: " << std::endl;
    data1.print();
    std::cout << std::endl;
    std::cout << "data2 after swap: " << std::endl;
    data2.print();




    return 0;
}