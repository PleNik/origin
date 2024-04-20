#include"my_vector.h"


int main() {
    setlocale(LC_ALL, "ru");
    try {
        
        my_vector<int> v1;
        std::cout << "v1 before fill:" << std::endl;
        std::cout << "size v1 = " << v1.size() <<" capacity v1 = "<<v1.capacity()<< std::endl;
        std::cout << std::endl;
       
        v1.push_back(23);
        v1.push_back(45);
        v1.push_back(2);
        v1.push_back(245);
        v1.push_back(11);

        for (int i = 0; i < v1.size(); i++)
            std::cout << v1.at(i) << " ";
        std::cout << std::endl;

        std::cout << "v1 after fill:" << std::endl;
        std::cout << "size v1 = " << v1.size() << " capacity v1 = " << v1.capacity() << std::endl;
        std::cout << std::endl;

        my_vector<int> v2(4);
        std::cout << "v2 before fill:" << std::endl;
        std::cout << "size v2 = " << v2.size() << " capacity v2 = " << v2.capacity() << std::endl;
        std::cout << std::endl;

        v2.push_back(23);
        v2.push_back(45);
        v2.push_back(2);
        v2.push_back(245);
        v2.push_back(11);

        for (int i = 0; i < v2.size(); i++)
            std::cout << v2.at(i) << " ";
        std::cout << std::endl;

        std::cout << "v2 after fill:" << std::endl;
        std::cout << "size v2 = " << v2.size() << " capacity v2 = " << v2.capacity() << std::endl;
        std::cout << std::endl;

        my_vector<std::string> v3;
        v3.push_back("Hello,");
        v3.push_back("World!");

        for (int i = 0; i < v3.size(); i++)
            std::cout << v3.at(i) << " ";
        std::cout << std::endl;

        v3.at(5); //exception
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}


