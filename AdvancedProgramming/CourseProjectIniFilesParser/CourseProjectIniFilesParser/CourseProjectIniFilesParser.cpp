#include <iostream>
#include<fstream>
#include<map>
#include<string>
#include<Windows.h>
//#include<iterator>

struct Values {
	std::string variable1;
	std::string value1;
	std::string variable2;
	std::string value2;
};

class Format {
public:
	Format(char section_start, char section_end, char assign, char comment):
		char_section_start(section_start),
		char_section_end(section_end),
		char_assign(assign),
		char_comment(comment)
	{}
		
	Format() : Format('[', ']', '=', ';') {}

	bool is_section_start(char ch) const {
		return ch == char_section_start;
	}

	bool is_section_end(char ch) const {
		return ch == char_section_end;
	}
	bool is_assign(char ch) const {
		return ch == char_assign;
	}
	bool is_comment(char ch) const {
		return ch == char_comment;
	}

	const char char_section_start;
	const char char_section_end;
	const char char_assign;
	const char char_comment;
};


class ini_parser {
public:
	ini_parser(std::string& file_name) {

	}

	ini_parser() : format(std::make_shared<Format>()) {};
	ini_parser(std::shared_ptr<Format> fmt) : format(fmt) {};

private:
	using String = std::string;
	using Section = std::multimap<String, String>;
	using Sectinons = std::multimap<String, Section>;
	std::shared_ptr<Format> format;

	Sectinons sections;
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string file_name = "IniFile.ini";
	std::ifstream fin;
	std::string line;
	std::multimap<std::string, Values> Sections;;

	fin.exceptions(std::ifstream::badbit | std::ifstream::failbit); //включение в классе ifstream обработки исключений

	try {
		fin.open(file_name);
		std::string section;
		int count_of_line = 1;

		while (!fin.eof()) {
			std::getline(fin, line);
			const auto lenght = line.length();
			if (lenght > 0) {
				const auto pos_assign = find(line.begin(), line.end(), '=');
				const auto pos_semicolon = find(line.begin(), line.end(), ';');
				if (line.front() == '[') {
					if (line.back() == ']') {
						section = line.substr(1, lenght - 2);
						Sections.insert({section, {}});
					}
					else { 
						throw "Incorrect syntax in line " + std::to_string(count_of_line);
					}
				}
				else if (line.front() == ';') {

				}
				else if (pos_assign != line.begin() && pos_assign != line.end()) {
					std::string variable(line.begin(), pos_assign);
					std::cout << variable << std::endl;

					auto sec = Sections.find(section);
					sec->second.variable1 = variable;

					if (pos_semicolon != line.begin() && pos_semicolon != line.end()) {
						std::string value(pos_assign + 1, pos_semicolon);
						sec->second.value1 = value;
					}
						
					
					
				
				}

			}
		
			
			count_of_line ++;
		}

	}
	catch (const std::ifstream::failure& ex) {
		std::cout << ex.what() << std::endl; //описание ошибки
		std::cout << ex.code() << std::endl;  //код ошибки
	}

	catch (const std::string& uncoreret_sintax) {
		std::cout << uncoreret_sintax << std::endl;
	}






	return 0;
}