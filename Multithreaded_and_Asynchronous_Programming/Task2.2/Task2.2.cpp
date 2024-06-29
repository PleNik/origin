#include <iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<iomanip>

#include"ConsolParameter.h"
#include"Timer.h"

std::mutex mtx1;
std::mutex mtx2;

void printProcess(int sleep_for, int index, int numThread) {

    Consol_parameter con_par;
    Timer timer;
    static int y = 1;
   
    timer.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_for));

    mtx1.lock();
    std::cout << index << "\t";
    std::cout << std::this_thread::get_id() << std::endl;
    
    for (size_t x = 16; x < 26; x++) {
        mtx2.lock();
        con_par.SetPosition(x, y);
        con_par.SetColor(15, 15);
        std::cout << " " << std::endl;
        mtx2.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        con_par.SetColor(15, 0);
        con_par.SetPosition(30, y);
        timer.print();
    }
    
    mtx1.unlock();
    y++;
}


int main() {

    setlocale(LC_ALL, "ru");

    srand(time(NULL));

    int numberOfThread = 4;

    Consol_parameter c_par;
    Timer timer;

    std::cout << "#       id      Progress Bar";
    c_par.SetPosition(30, 0);
    std::cout << "Time" << std::endl;

    std::vector<std::thread> v_th(numberOfThread);

    timer.start();
    for (size_t i = 0; i < numberOfThread; i++) {
        v_th[i] = std::thread(printProcess, rand() % 5001, i, numberOfThread);
    }

    for (size_t i = 0; i < numberOfThread; i++) {
        v_th[i].join();
    }
   
   
    return 0;
}