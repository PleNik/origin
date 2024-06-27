#include <iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<iomanip>

#include"ConsolParameter.h"
#include"Timer.h"

std::mutex mtx;

void printProcess(int sleep_for, int numThread) {

    static int y = 1;

    Timer timer;
    Consol_parameter c_param;

    std::unique_lock mutexUniq(mtx);
    timer.start();

    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_for));

    std::cout << numThread << "\t" << std::this_thread::get_id() << "\t";

    c_param.SetColor(15, 15);
    for (size_t i = 0; i < sleep_for / 1000; i++) {
        std::cout << '#' << " ";
    }
    c_param.SetColor(15, 0);

    c_param.SetPosition(50, y);
    y++;

    timer.print();

}


int main() {

    int numberOfThreads = 5;

    Consol_parameter c_par;

    std::vector<std::thread> vt(numberOfThreads);

    std::cout << "#       id      Progress Bar";
    c_par.SetPosition(50, 0);

    std::cout << "Time" << std::endl;

    for (size_t i = 0; i < numberOfThreads; i++) {
        vt[i] = std::thread(printProcess, (rand() % (10000 - 1000 + 1) + 1000), i);
    }

    for (size_t i = 0; i < numberOfThreads; i++) {
        vt[i].join();
    }

    return 0;
}