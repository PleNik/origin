#include <iostream>
#include<future>
#include<thread>
#include<list>


template<typename Iterator, typename Func>
void parallel_for_each(Iterator first, Iterator last, Func f) {
	unsigned long const length = std::distance(first, last);
	unsigned long const max_chunk_size = 2;
	if (length <= max_chunk_size) {
		f();
		return;
	}

	Iterator mid_point = first;
	std::advance(mid_point, length / 2);
	std::future<void> first_half_result = std::async(parallel_for_each<Iterator, Func>, first, mid_point, f);
	std::future<void> second_half_result = std::async(parallel_for_each<Iterator, Func>, mid_point, last, f);
	

	first_half_result.get();
	second_half_result.get();
}

int main() {

	std::list<int> myList = { 15, 64, 954, 23, 88 };

	auto it_begin = myList.begin();
	auto it_end = myList.end();
	parallel_for_each(it_begin, it_end, [&]() {
		for (auto it = it_begin; it != it_end; it++) {
			std::cout << *it << std::endl;
		}
		std::cout << std::endl;
		});
	
	return 0;
}