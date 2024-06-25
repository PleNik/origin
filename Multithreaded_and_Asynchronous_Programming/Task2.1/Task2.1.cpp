#include <iostream>
#include<thread>
#include<chrono>

class QueueAtTheWindow {

public:
    QueueAtTheWindow(int numberOfClients) : m_numberOfClients(numberOfClients) { m_numberOfClientsMax = m_numberOfClients + 10; }

    void clientsQueue() {
       
        for (;;) {
            std::cout << "ID thread = " << std::this_thread::get_id() << "\tclients\t" << m_numberOfClients << std::endl;
            int numberOfClientsWas = m_numberOfClients.load();
            if (numberOfClientsWas >= m_numberOfClientsMax) {
                break;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

            m_numberOfClients.fetch_add(1, std::memory_order_relaxed);

        }
       
    }

    void cashier() {
       
        for (;;) {
            std::cout << "ID thread = " << std::this_thread::get_id() << "\tcashier\t" << m_numberOfClients << std::endl;
            int numberOfClientsWas = m_numberOfClients.load();
            if (numberOfClientsWas <= 0) {
                break;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            if (m_numberOfClients.compare_exchange_weak(numberOfClientsWas, numberOfClientsWas - 1)) {
                continue;
            }

        }

    }

    int getNumberOfClients() {
        return m_numberOfClients;
    }

private:
    std::atomic<int> m_numberOfClients;
    int m_numberOfClientsMax;

    void printNumberOfClients() {
        std::cout << "Number of clients: " << getNumberOfClients() << std::endl;
    }
};


int main() {

    srand(time(0));
    int count = rand() % 19 + 2;
    int countMax = count + 10;

    QueueAtTheWindow queue(count);

    std::thread th1([&queue]() {queue.clientsQueue(); });
    std::thread th2([&queue]() {queue.cashier(); });


    th1.join();
    th2.join();

    std::cout << "Number of clients " << queue.getNumberOfClients() << std::endl;

    return 0;
}