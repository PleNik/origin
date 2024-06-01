#include <iostream>
#include<fstream>
#include<map>
#include<string>


class ini_parser {
public:
    ini_parser(std::string& f_name) {
        file_name = f_name;
        count_of_line = 1;

        fillingSections();
    }

    //шаблонный метод
    template<typename T>
    T get_value(std::string section_variable) {
        T result{};

        std::string string_value = get_value_string(section_variable);

        if constexpr (std::is_same<int, T>::value) {
            result = std::stoi(string_value);
        }
        else if constexpr (std::is_same<double, T>::value) {

            result = std::stod(string_value);
        }
        else if constexpr (std::is_same<float, T>::value) {
            result = std::stof(string_value);
        }
        else if constexpr (std::is_same<std::string, T>::value) {
            result = string_value;
        }
        else {
            static_assert(sizeof(T) == -1, "no implementation for this type!");
        }

        return result;
    }


private:
    std::string file_name;
    std::string section_name;
    std::string variable;
    std::string value;
    std::ifstream fin;
    std::string line;
    std::map<std::string, std::map<std::string, std::string>> Sections;
    int count_of_line;


    void fillingSections() {
        fin.exceptions(std::ifstream::badbit | std::ifstream::failbit); //включение в классе ifstream обработки исключений

        fin.open(file_name);
        std::string section_name;
        int count_of_line = 1;

        while (!fin.eof()) {
            std::getline(fin, line);
            const auto lenght = line.length();
            if (lenght > 0) {

                //проверка на корректность синтаксиса в названии секции
                if (line.find('[') != std::string::npos && line.find(']') != std::string::npos) {
                    size_t pos_section_start = line.find('[');
                    size_t pos_section_end = line.find(']');
                    section_name = line.substr(pos_section_start + 1, pos_section_end - pos_section_start - 1);
                    Sections.insert(std::pair<std::string, std::map<std::string, std::string>>(section_name, {}));
                }
                else if ((line.find('[') != std::string::npos && line.find(']') == std::string::npos) || (line.find(']') != std::string::npos && line.find('[') == std::string::npos)) {

                    std::string str = std::to_string(count_of_line);
                    const char* str_excep = str.c_str();
                    throw std::exception(str_excep);
                }

                else if (line.front() == ';') {
                    //игнорируем комментарий
                }
                else if (line.find('=') != std::string::npos) {
                    auto pos_assign = std::find(line.begin(), line.end(), '=');
                    line.erase(remove(line.begin(), pos_assign, ' '), pos_assign); //удаление пробелов до знака равенства
                    pos_assign = std::find(line.begin(), line.end(), '=');

                    //удаление пробелов после знака равенства
                    auto it = pos_assign + 1;
                    if (it != line.end()) {
                        while (*it == ' ') {
                            it++;
                        }
                    }
                    line.erase(remove(pos_assign, it, ' '), it);

                    std::string variable(line.begin(), pos_assign);

                    if (line.find(';') != std::string::npos) {
                        const auto pos_semicolon = std::find(line.begin(), line.end(), ';');
                        std::string value(pos_assign + 1, pos_semicolon);

                        auto it_variable = Sections.find(section_name)->second.find(variable);
                        if (it_variable != Sections.find(section_name)->second.end()) {

                            //если элемент уже существует, удалеяем его для дальнейшего перезаписывания
                            Sections.find(section_name)->second.erase(it_variable);
                        }

                        Sections.find(section_name)->second.insert(std::make_pair(variable, value));

                    }
                    else {
                        std::string value(pos_assign + 1, line.end());

                        auto it_variable = Sections.find(section_name)->second.find(variable);
                        if (it_variable != Sections.find(section_name)->second.end()) {
                            //если элемент уже существует, удалеяем его для дальнейшего перезаписывания
                            Sections.find(section_name)->second.erase(it_variable);
                        }

                        Sections.find(section_name)->second.insert(std::make_pair(variable, value));
                    }

                }
            }
            count_of_line++;
        }

    }

    std::string get_value_string(const std::string& str) {
        std::string section, var, val;

        size_t index_dot = str.find('.');
        var = str.substr(index_dot + 1);
        section = str.substr(0, str.length() - var.length() - 1);

        if (Sections.find(section)->second.count(var) == 0) {
            std::cout << "Переменной " << var << " в секции " << section << " нет" << std::endl;
            std::cout << "В данной секции есть следующие переменные:" << std::endl;

            for (const auto& it : Sections.find(section)->second) {
                std::cout << it.first << std::endl;
            }
            throw std::string{ "Переменная не найдена" };
        }
        val = Sections.find(section)->second.find(var)->second;

        if (val.empty())
            throw "Нет значения переменной";

        return val;
    }
};


int main() {
    setlocale(LC_ALL, "ru");

    try {
        std::string file_name = "IniFile.ini";

        ini_parser parser(file_name);

        std::cout << parser.get_value<double>("Section1.var1") << std::endl;

        std::cout << parser.get_value<float>("Section1.var1") << std::endl;

        std::cout << parser.get_value<int>("Section2.var1") << std::endl;

        std::cout << parser.get_value<std::string>("Section2.var2") << std::endl;

        //std::cout << parser.get_value<float>("Section2.var") << std::endl;

        std::cout << parser.get_value<float>("Section4.Vid") << std::endl;

    }
    catch (const std::ifstream::failure& ex) {
        std::cout << ex.what() << std::endl; //описание ошибки
        std::cout << ex.code() << std::endl;  //код ошибки
        std::cout << "Ошибка открытия файла" << std::endl;
    }

    catch (const char* ex) {
        std::cout << "Нет значения переменной" << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << "Не корректный синтаксис в строке " << ex.what() << std::endl;
    }
    catch (const std::string& variable_is_missing) {
        std::cout << variable_is_missing << std::endl;
    }

    return 0;
}