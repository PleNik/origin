#include <iostream>
#include<ctime>
#include<vector>
#include<future>
#include<thread>


void fillingArray(std::vector<int>& v, int size) {
	for (size_t i = 0; i < size; i++)
		v.emplace_back(rand() % 100);
}

void findSmallestElement(std::promise<int> index, std::vector<int>& v, int startPosition, int size) {
	int smalestPosition = startPosition;

	for (size_t i = startPosition; i < size; i++) {
		if (v[i] < v[smalestPosition])
			smalestPosition = static_cast<int>(i);
	}

	index.set_value(smalestPosition);
}

void selectionSort(std::vector<int>& v, int size) {

	for (size_t i = 0; i < size; i++) {
		std::promise<int> index;

		std::future<int> indexFuture = index.get_future();

		std::thread findSmallestElememtThread([&]() {findSmallestElement(std::move(index), v, i, size ); });

		findSmallestElememtThread.detach();

		const auto resultIndex = indexFuture.get();

		int smallestPosition = resultIndex;

		std::swap(v[i], v[smallestPosition]);
	}
}


int main() {

	srand(time(NULL));

	const int numberOfElements = 5;

	std::vector<int> vList;

	vList.reserve(numberOfElements);

	fillingArray(vList, numberOfElements);

	std::cout << "==========\tvList before sorting\t============" << std::endl;
	for (const auto& i : vList)
		std::cout << i << std::endl;

	selectionSort(vList, numberOfElements);

	std::cout << "==========\tvList after sorting\t============" << std::endl;
	for (const auto& i : vList)
		std::cout << i << std::endl;
	
	



	return 0;
}