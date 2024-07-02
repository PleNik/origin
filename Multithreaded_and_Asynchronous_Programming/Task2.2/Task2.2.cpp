#include <iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<iomanip>
#include<exception>

#include"ConsolParameter.h"
#include"Timer.h"

std::mutex mtx;

class ThreadException : public std::exception {
   
};

void printProcess( int sleepFor, int index, int numberOfTreads) {

    srand(time(NULL));

    Consol_parameter consol_parameter;
    Timer timer;

    timer.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepFor));

    mtx.lock();
    consol_parameter.SetPosition(0, index+1);
    std::cout << index;
    consol_parameter.SetPosition(6, index + 1);
    std::cout << std::this_thread::get_id() << std::endl;
    mtx.unlock();
    for (size_t x = 12; x < 22; x++) {
        try {
            
            mtx.lock();
            consol_parameter.SetPosition(x, index + 1);
            int val_exc = rand() % 10;
            if (val_exc == 3) {
                throw ThreadException();
            }
            consol_parameter.SetColor(15, 15);
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            std::cout << " " << std::endl;
            mtx.unlock();

        }
        catch (...){
            consol_parameter.SetColor(20, 20);
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            std::cout << " " << std::endl;
            mtx.unlock();
        }
        
        
        consol_parameter.SetColor(15, 0);
        
    }
    mtx.lock();
    consol_parameter.SetPosition(30, index + 1);
    timer.print();
    mtx.unlock();
  
    consol_parameter.SetPosition(0, numberOfTreads + 1);
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