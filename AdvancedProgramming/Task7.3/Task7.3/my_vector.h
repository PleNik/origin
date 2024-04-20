#pragma once

#include<iostream>

#include"indexException.h"

template<class T>
class my_vector {
public:
    my_vector() {
        index = 0;
        logical_size = 0;
        actual_size = 1;
        this->data = new T[actual_size]{};
    }

    my_vector(unsigned size) {
        index = 0;
        logical_size = actual_size = size;
        this->data = new T[actual_size]{};
    }

    //конструктор копирования
    my_vector(const my_vector& other) {
        this->actual_size = other.actual_size;
        this->logical_size = other.logical_size;

        this->data = new T[other.actual_size];

        for (unsigned i = 0; i < other.logical_size; i++)
            this->data[i] = other.data[i];
    }

    //оператор присваивания
    my_vector& operator=(const my_vector& other) {
        delete[] this->data;

        this->actual_size = other.actual_size;
        this->logical_size = other.logical_size;

        this->data = new T[other.actual_size];

        for (unsigned i = 0; i < other.logical_size; i++)
            this->data[i] = other.data[i];

        return *this;
    }

    T at(unsigned index) {
        if (index >= logical_size) {
            throw indexIncorrectException();
        }
        else {
            return data[index];
        }
    }

    void push_back(T value) {
        if (logical_size < actual_size) {
            data[logical_size] = value;
            logical_size++;
        }
        else {
            actual_size *= 2;
            T* new_data = new T[actual_size];
            for (unsigned i = 0; i < logical_size; i++)
                new_data[i] = data[i];
            new_data[logical_size] = value;
            logical_size++;

            delete[] data;
            data = new_data;
        }
    }

    unsigned size() {
        return logical_size;
    }

    unsigned capacity() {
        return actual_size;
    }

    ~my_vector() {
        delete[] data;
    }

private:
    unsigned logical_size;
    unsigned actual_size;
    T* data;
    unsigned index;
};

