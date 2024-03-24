#include <iostream>
#include<variant>
#include<vector>

std::variant<int, std::string, std::vector<int>> get_variant() {
    std::srand(std::time(nullptr));
    int random_variable = std::rand() % 3;

    std::variant<int, std::string, std::vector<int>> result;
    switch (random_variable)
    {
    case 0:
        result = 5;
        break;
    case 1:
        result = "string";
        break;
    case 2:
        result = std::vector<int>{ 1,2,3,4,5 };
        break;
    default:
        break;
    }
    return result;
}

int main() {
    auto try_value = get_variant();

    if (bool is_int = std::holds_alternative<int>(try_value)) {
        auto try_int = std::get_if<int>(&try_value);
        std::cout << *try_int * 2 << std::endl;
    }
    else if (bool is_string = std::holds_alternative<std::string>(try_value)) {
        auto try_string = std::get_if<std::string>(&try_value);
        std::cout << *try_string << std::endl;
    }
    else {
        auto try_vector = std::get_if<std::vector<int>>(&try_value);
        for (const auto& it : *try_vector)
            std::cout << it << " ";
    }
    
    return 0;
}