#include <iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<iomanip>

#include"ConsolParameter.h"
#include"Timer.h"

std::mutex mtx;

void printProcess( int sleepFor, int index, int numThread) {

    Consol_parameter consol_parameter;
    Timer timer;
  
    static int y = 1;

    timer.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepFor));

    consol_parameter.SetPosition(0, y);
    std::cout << index;
    consol_parameter.SetPosition(6, y);
    std::cout << std::this_thread::get_id() << std::endl;

    for (size_t x = 12; x < 22; x++) {
        mtx.lock();
        consol_parameter.SetPosition(x, y);
        consol_parameter.SetColor(15, 15);
        std::cout << " " << std::endl;
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        
        consol_parameter.SetColor(15, 0);
    }
   
    consol_parameter.SetPosition(30, y);
    timer.print();
   
    y++;
}


int main() {

    Consol_parameter consol_parametr;

    int numberOfThreads = 5;
    int calculationLength = 500;

    consol_parametr.SetPosition(0, 0);
    std::cout << '#';

    consol_parametr.SetPosition(6, 0);
    std::cout << "id";

    consol_parametr.SetPosition(12, 0);
    std::cout << "Progress Bar";

    consol_parametr.SetPosition(30, 0);
    std::cout << "Time";

    std::thread* t = new std::thread[numberOfThreads];

    for (size_t i = 0; i < numberOfThreads; i++)
        t[i] = std::thread(printProcess, calculationLength, i, numberOfThreads);

    for (size_t i = 0; i < numberOfThreads; i++)
        t[i].join();

    delete[]t;


    return 0;
}