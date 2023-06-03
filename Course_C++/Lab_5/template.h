#ifndef COURSE_C___TEMPLATE_H
#define COURSE_C___TEMPLATE_H

#include "exception.h"

template<typename T>
T findMax(T *arr, int n) {
    if (n <= 0) {
        throw Exception("Array size must be greater than 0");
    }

    T maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if(arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    return maxElement;
}

#endif //COURSE_C___TEMPLATE_H
