#include <iostream>
#include<vector>
#include<random>
#include<thread>
#include <iomanip>

void FillingVector(std::vector<int>& v, int sid) {
    
    std::mt19937 gen(sid);

    std::uniform_int_distribution<int> dis(0, 1000);

    auto rand_num([=]() mutable {return dis(gen); });

    std::generate(v.begin(), v.end(), rand_num);

}

void SumVectors(std::vector<int>& v1, std::vector<int>& v2, std::vector<int>& v_res, int start, int end) {
 
    for (size_t i = start-1; i < end; i++) {

        v_res[i] = v1[i] + v2[i];

    }
}

int main() {

    setlocale(LC_ALL, "ru");

    int number_of_threads = 16;


    for (size_t j = 1; j <= 16; j *= 2) {
        int number_of_threads = j;
        if (number_of_threads == 1) {
            std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
            std::cout << std::endl;
            std::cout << "                      1000            10000           100000          1000000" << std::endl;
        }
           
        std::cout.width(2);
        std::cout << number_of_threads << " потоков " ;

        for (size_t k = 1000; k <= 1000000; k *= 10) {
            int size_vector = k;
           std::vector<int> vc1(size_vector), vc2(size_vector), vc_res(size_vector);
            FillingVector(vc1, 342);
            FillingVector(vc2, 32);

            int start = 1;
            int _end = size_vector / number_of_threads;
            int end = _end;

            const auto startCalcTime(std::chrono::steady_clock::now());

            std::vector<std::thread> tv;
            for (size_t i = 0; i < number_of_threads; i++) {
                if (i == number_of_threads - 1)
                    end = number_of_threads;
                tv.push_back(std::thread(SumVectors, std::ref(vc1), std::ref(vc2), std::ref(vc_res), start, end));
                start = end + 1;
                end += _end;
            }

            for (auto& t : tv) {
                t.join();
            }

            const auto endCalcTime{ std::chrono::steady_clock::now() };
            const auto time = std::chrono::duration<double>(endCalcTime - startCalcTime).count();
            std::cout << std::setw(15)<<time << "s ";
        }
        std::cout << std::endl;
    }
   

    return 0;
}