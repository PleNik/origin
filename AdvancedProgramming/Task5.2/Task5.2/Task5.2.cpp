#include <iostream>

template<class T>
class Table {
	unsigned int m_rows;
	unsigned int m_cols;
	T** arr;

public:
	Table(int rows, int cols) : m_rows(rows), m_cols(cols) {
		arr = new T * [m_rows];
		for (int i = 0; i < rows; i++)
			arr[i] = new T[m_cols];
	}

	~Table() {
		for (int i = 0; i < m_rows; i++)
			delete arr[i];

		delete[] arr;
	}

	void add_element(T value, unsigned rows, unsigned cols) {
		arr[rows][cols] = value;
	}

	T get_element(unsigned rows_i, unsigned cols_i){
		return arr[rows_i][cols_i];
	}
};


int main() {
	auto test = Table<int>(2, 3);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			test.add_element(j, i, j);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << test.get_element(i, j) << " ";
		}
	}
}
