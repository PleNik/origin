#pragma once
#include<exception>

class indexIncorrectException : public std::exception {
public:
    const char* what() const noexcept override;
};
