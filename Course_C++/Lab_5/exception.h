#ifndef COURSE_C___EXCEPTION_H
#define COURSE_C___EXCEPTION_H

#include <iostream>
#include <exception>

class Exception : public std::exception {
public:
    Exception(const char* errr) : error(errr) {}
    const char* what() const noexcept {
        return error;
    }
private:
    const char* error;
};

template<typename T, int n>
class Array {
private:
    T arr[n];
public:
    Array() = default;

    Array(int cnt) {
        if (cnt > n) {
            throw Exception("ERROR!");
        }
        for (int i = 0; i < cnt; i++) {
            std::cin >> arr[i];
        }
    }

    T& operator[](int i) {
        if (i < 0 || i >= n) {
            throw Exception("Index out of range!");
        }

        return arr[i];
    }
};

#endif //COURSE_C___EXCEPTION_H
