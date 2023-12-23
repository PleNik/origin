#include <iostream>
#include<fstream>
#include<string>

int* create_array(int size); //функция создания динамического массива
void delete_array(int* arr); //функция очистки выделеной под массивы памяти

int main()
{
	int size_arr_1, size_arr_2; //размеры первого и второго одномерных целочисленных массива

	std::string path_in = "in.txt";
	std::string path_out = "out.txt";

	std::string str; //буферная переменная для считывания данных из файла

	std::ifstream fin(path_in);

	//считываение из файла размеров массивов
	if (fin.is_open())
	{
		fin >> str;
		size_arr_1 = std::stoi(str); //размер первого массива

		for (int i = 0; i < size_arr_1; i++)
		{
			fin >> str;
		}

		fin >> str;
		size_arr_2 = std::stoi(str); //размер второго массива

		fin.close();

	}
	else
		std::cout << "Error opening file!" << std::endl;

	//создание первого и второго массивов
	int* array_1 = create_array(size_arr_1);
	int* array_2 = create_array(size_arr_2);

	//считывание из файла массивов
	fin.open(path_in);

	if (fin.is_open())
	{
		fin >> str;

		//считывание первого массива
		for (int i = 0; i < size_arr_1; i++)
		{
			fin >> str;
			array_1[i] = std::stoi(str);
		}

		fin >> str;

		//считывание второго массива
		for (int i = 0; i < size_arr_2; i++)
		{
			fin >> str;
			array_2[i] = std::stoi(str);
		}

		fin.close();

	}
	else
		std::cout << "Error opening file!" << std::endl;

	//преобразование массивов
	int* array_2_1 = create_array(size_arr_2); //создание нового массива 2
	for (int i = 0; i < size_arr_2; i++)
	{
		if (!i)
		{
			array_2_1[i] = array_2[size_arr_2 - 1];
		}
		else
		{
			array_2_1[i] = array_2[i - 1];
		}
	}

	int* array_1_1 = create_array(size_arr_1); //создание нового массива 1
	for (int i = size_arr_1 - 1; i >= 0; i--)
	{
		if (i == size_arr_1 - 1)
		{
			array_1_1[size_arr_1 - 1] = array_1[0];
		}
		else
		{
			array_1_1[i] = array_1[i + 1];
		}
	}

	//запись преобразованных массивов в файл
	std::ofstream fout(path_out);

	if (fout.is_open())
	{
		fout << size_arr_2 << std::endl;
		for (int i = 0; i < size_arr_2; i++)
		{
			fout << array_2_1[i] << " ";
		}

		fout << std::endl;
		fout << size_arr_1 << std::endl;
		for (int i = 0; i < size_arr_1; i++)
		{
			fout << array_1_1[i] << " ";
		}

		fout.close();

	}
	else
		std::cout << "Error opening file!" << std::endl;

	//очистка памяти
	delete_array(array_1);
	delete_array(array_2);

	delete_array(array_2_1);
	delete_array(array_1_1);

	return 0;
}

int* create_array(int size)
{
	int* arr = new int[size];

	return arr;
}

void delete_array(int* arr)
{
	delete[] arr;
}
