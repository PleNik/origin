#include <iostream>
#include<atomic>
#include<chrono>
#include<functional>
#include<mutex>
#include<queue>
#include<thread>
#include<condition_variable>

template<typename T>
class safe_queue {
public:
	void push(const T& aTask) {
		std::lock_guard lockGuard{ mMutex };
		mQueueTask.push(aTask);
		// после окончания операции нотифицируется условная переменная;
		mCondVar.notify_one();
	}
	void pop() { //находится в ожидании, пока не придёт уведомление на условную переменную. При нотификации условной переменной данные считываются из очереди;
		std::lock_guard lockGuard{ mMutex };
		mCondVar.wait(mMutex);
		mQueueTask.pop();
	}

	const std::queue<T>& getTask() {
		return mQueueTask;
	}

private:
	std::mutex mMutex;
	std::queue<T> mQueueTask;
	std::condition_variable mCondVar;
};


class thread_pool {
public:
	thread_pool(int aMaxThreadCount = std::thread::hardware_concurrency()) {
		for (size_t i = 0; i < aMaxThreadCount - 3; i++) {
			mThreadVector.push_back(std::thread(work));
		}
	}

	~thread_pool() {
		for (auto& thread : mThreadVector)
			thread.join();
	}

	void submit(const std::function<void()>& aTask) {
		mSafeQueue.push(aTask);
	}

	void work() {
		if (!mSafeQueue.getTask().empty()) {
			auto task = mSafeQueue.getTask().front();
			mSafeQueue.pop();
			task();

		}
		else {
			std::this_thread::yield();
		}
	}

private:
	std::vector<std::thread> mThreadVector;
	safe_queue <void()> mSafeQueue;
};

void func1() {
	std::this_thread::sleep_for(std::chrono::microseconds(200));

	std::cout << "Working thread id: " << std::this_thread::get_id() << " func1" << std::endl;
}

void func2() {
	std::this_thread::sleep_for(std::chrono::microseconds(200));

	std::cout << "Working thread id: " << std::this_thread::get_id() << " func2" << std::endl;
}

int main() {

	
	return 0;
}