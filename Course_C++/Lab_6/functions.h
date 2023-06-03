#ifndef COURSE_C___FUNCTIONS_H
#define COURSE_C___FUNCTIONS_H

#include <iostream>
#include <algorithm>

struct CPoint {
    int x;
    int y;
};

bool operator==(const CPoint& left, const CPoint& right) {
    return left.x == right.x && left.y == right.y;
}

template <typename InputIterator, typename Predicate>
bool none_of_custom(InputIterator first, InputIterator last, Predicate predicate) {
    while (first != last) {
        if (predicate(*first)) {
            return false;
        }
        ++first;
    }
    return true;
}

template <typename ForwardIterator, typename Compare>
bool is_sorted_custom(ForwardIterator first, ForwardIterator last, Compare comp) {
    if (first == last)
        return true;

    ForwardIterator next = first;
    while (++next != last) {
        if (comp(*next, *first)) {
            return false;
        }
        ++first;
    }

    return true;
}

template <typename InputIterator, typename T>
InputIterator find_not_custom(InputIterator first, InputIterator last, const T& value) {
    while (first != last) {
        if (*first != value) {
            return first;
        }
        ++first;
    }
    return last;
}

bool is_negative(int num) {
    return num < 0;
}

bool is_origin(const CPoint& point) {
    return point.x == 0 && point.y == 0;
}

bool lessThanByX(const CPoint& left, const CPoint &right) {
    return left.x < right.x;
}

#endif //COURSE_C___FUNCTIONS_H
