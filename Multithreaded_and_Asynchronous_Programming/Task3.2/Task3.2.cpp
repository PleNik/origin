#include <algorithm>
#include <future>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

template <typename TIterator, typename TProc>
void forEach(TIterator aBeginIterator, TIterator aEndIterator,
    TProc aProc) {
    if (aEndIterator == aBeginIterator) {
        return;
    }

    auto procFuture{ std::async(aProc, *aBeginIterator) };
    forEach(aBeginIterator + 1, aEndIterator, aProc);
    procFuture.wait();
}

std::mutex mutex;

void bigDelay(int aValue) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::lock_guard mutexLockGuard{ mutex };
    std::cout << "aValue: " << aValue << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

int main() {
    std::vector<int> vector{ 2, 5, 1, 6, 8, 10, 15, 11 };

    bigDelay(500);
    forEach(vector.begin(), vector.end(), bigDelay);

    return 0;
}