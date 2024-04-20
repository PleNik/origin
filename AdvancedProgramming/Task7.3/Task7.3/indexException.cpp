#include"indexException.h"

const char* indexIncorrectException::what() const noexcept {
	return "индекс выходит за пределы массива";
}
