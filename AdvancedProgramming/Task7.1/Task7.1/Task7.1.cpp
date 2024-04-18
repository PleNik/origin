#include <iostream>
#include <vector>
#include <list>

struct Simbols {
    char simbol;
    int count_simbol;
};

int main() {

    try {
        std::cout << "[IN]: ";
        std::vector<char> char_v = { 'H','e','l','l','o',' ','w','o','r','l','d','!','!' };

        for (const auto& el : char_v)
            std::cout << el;

        std::cout << std::endl;

        std::list<Simbols> simbols_list;
        

        Simbols new_s;
        int count = 1;
        for (int i = 0; i < char_v.size(); i++) {
            for (int j = i + 1; j < char_v.size(); j++) {
                if (char_v[i] == char_v[j])
                    count++;
            }
            new_s = { char_v[i], count };

            if (simbols_list.begin() == simbols_list.end()) {
                simbols_list.push_back(new_s);
            }

            bool is_simbol = true;
            for (auto itr = simbols_list.begin(); itr != simbols_list.end(); itr++) {
                
                if (itr->simbol == char_v[i]) {
                    count = 1;
                    is_simbol = true;
                    break;
                }
                else
                    is_simbol = false;

            }
            if (!is_simbol) {
                simbols_list.push_back(new_s);
                count = 1;
            }
        }

        auto compare = [](const Simbols& a, const Simbols& b) {return a.count_simbol > b.count_simbol; };
        simbols_list.sort(compare);

        std::cout << "[OUT]:" << std::endl;
        for (const auto& i : simbols_list)
            std::cout << i.simbol << ": " << i.count_simbol << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}