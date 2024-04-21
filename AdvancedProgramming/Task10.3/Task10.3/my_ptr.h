#pragma once

namespace msp {
	template<typename T>
	class my_unique_ptr {
	public:
		my_unique_ptr(T* ptr) {
			this->ptr = ptr;
			std::cout << "Constructor" << std::endl;
		}
		~my_unique_ptr() {
			delete ptr;
			std::cout << "Destructor" << std::endl;
		}

		T& operator * () {
			return *ptr;
		}

		T* get() {
			return ptr;
		}

		my_unique_ptr& operator = (my_unique_ptr a) = delete;
		my_unique_ptr(const my_unique_ptr& a) = delete;

		T*& relese() {
			T* ptr_tmp = ptr;
			ptr = nullptr;
			return ptr_tmp;
		}

	private:
		T* ptr;
	};
}