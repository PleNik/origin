#include <iostream>
#include<thread>
#include<chrono>

void clients_queue(int& number_of_clients, int& max_number_of_clients) {

    while (number_of_clients != max_number_of_clients) {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tclients_queue\t" << number_of_clients << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        number_of_clients++;
    }
   
}

void cashier(int& number_of_clients) {

    while (number_of_clients) {
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tcashier\t" << number_of_clients << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        number_of_clients--;
    }
    
}


int main() {

    srand(time(0));
    int count = rand() % 19 + 2;
    int count_max = count + 10;

    std::thread th1(clients_queue, std::ref(count), std::ref(count_max));
    std::thread th2(cashier, std::ref(count));

    th1.join();
    th2.join();

    std::cout << "Number of clients: " << count << std::endl;

    return 0;
}