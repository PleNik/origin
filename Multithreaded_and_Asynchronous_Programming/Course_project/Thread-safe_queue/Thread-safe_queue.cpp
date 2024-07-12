#include <iostream>
#include<atomic>
#include<chrono>
#include<functional>
#include<mutex>
#include<queue>
#include<thread>
#include<condition_variable>
#include<vector>

template<typename TType>
class safe_queue {
public:
	bool empty() { return mQueue.empty(); }

	TType& front() { return mQueue.front(); }

	void pop() { mQueue.pop(); }

	void push(TType aTask) { mQueue.push(aTask); }

private:
	std::queue<TType> mQueue;
	std::mutex mMutex;
	std::condition_variable mConditionVariable;
};

class thread_pool {
public:
	thread_pool(const auto maxThreadCount) {
		for (size_t i = 0; i < maxThreadCount - 1; i++) {
			mThreadVector.push_back(std::thread(work));
		}
	}

	~thread_pool() {
		for (auto& thread : mThreadVector) {
			thread.join();
		}
	}

	void submit(std::function<void()> aTask1, std::function<void()> aTask2) {
		while (count < 10) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout << "Working thread id: " << std::this_thread::get_id() << " " << __FUNCTION__ << "..." << std::endl;
			std::lock_guard lockGuard{ mThread_poolMutex };
			mSafe_queue.push(aTask1);
			mSafe_queue.push(aTask2);
			count++;
		}
	}

	static void work() {

		while (count < 10 || !mSafe_queue.empty()) {
			std::lock_guard lockGuard(mThread_poolMutex);
			if (!mSafe_queue.empty()) {
				auto task = mSafe_queue.front();
				mSafe_queue.pop();
				task();
			}
			else
				std::this_thread::yield();
		}

	}

	static safe_queue<std::function<void()>> mSafe_queue;
	static std::atomic<int> count;
	static std::mutex mThread_poolMutex;

private:
	std::vector<std::thread> mThreadVector;
	
};

safe_queue<std::function<void()>> thread_pool::mSafe_queue{};
std::atomic<int> thread_pool::count{};
std::mutex thread_pool::mThread_poolMutex{};

std::mutex workQueueMutex;
std::queue<std::function<void()>> workQueue;
std::vector<std::thread> threadVector;
std::atomic<int> counter{};

void func1() {
	std::this_thread::sleep_for(std::chrono::microseconds(200));

	std::cout << "Working thread id: " << std::this_thread::get_id() << " " << __FUNCTION__ << "..." << std::endl;
}

void func2() {
	std::this_thread::sleep_for(std::chrono::microseconds(200));

	std::cout << "Working thread id: " << std::this_thread::get_id() << " " << __FUNCTION__ << "..." << std::endl;
}


int main() {
	std::cout << "Working thread id: " << std::this_thread::get_id() << " " << __FUNCTION__ << "..." << std::endl;
	
	thread_pool thP(std::thread::hardware_concurrency());
	thP.submit(func1, func2);
	
	
	return 0;
}