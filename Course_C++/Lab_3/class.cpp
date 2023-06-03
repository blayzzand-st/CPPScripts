#include <iostream>
#include <cmath>
#include <algorithm>
#include "class.h"

Triangle::Triangle(std::vector<Point> points) {
    this->points = points;
}

Point Triangle::getVertex1() const { return points[0]; }
Point Triangle::getVertex2() const { return points[1]; }
Point Triangle::getVertex3() const { return points[2]; }

double Triangle::area() const {
    double a = distance(points[0], points[1]);
    double b = distance(points[1], points[2]);
    double c = distance(points[2], points[0]);
    double p = (a + b + c) / 2.0;

    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::distance(const Point &point1, const Point &point2) {
    double dx = point2.x - point1.x;
    double dy = point2.y - point1.y;
    return std::sqrt(dx * dx + dy * dy);
}

void Triangle::move(std::vector<double> &vector) {
    for (int i = 0; i < 3; i++) {
        points[i].x += vector[0];
        points[i].y += vector[1];
    }
}

bool Triangle::operator==(const Triangle &other) const {
    if (area() == other.area()) { return true; }
    return false;
}

bool Triangle::operator!=(const Triangle &other) const {
    if (area() != other.area()) { return true; }
    return false;
}

bool Triangle::operator>(const Triangle &other) const {
    if (area() > other.area()) { return true; }
    return false;
}

bool Triangle::operator<(const Triangle &other) const {
    if (area() < other.area()) { return true; }
    return false;
}

void Triangle::operator+(std::vector<double> &vector) {
    move(vector);
}

/* SUBSET */
Subset::Subset() {
    std::fill(std::begin(elements), std::end(elements), false);
}

Subset::Subset(const std::vector<int> &elements_add) {
    for (int i = 0; i < 10; i++) {
        elements[i] = false;
    }

    for (auto element : elements_add) {
        add(element);
    }

}

void Subset::add(int element) {
    elements[element] = true;
}

void Subset::remove(int element) {
    elements[element] = false;
}

Subset Subset::operator+(const Subset &other) const {
    Subset result;
    for (int i = 0; i < 10; i++) {
        result.elements[i] = elements[i] || other.elements[i];
    }
    return result;
}

bool Subset::operator==(const Subset &other) const {
    for (int i = 0; i < 10; i++) {
        if (elements[i] != other.elements[i]) {
            return false;
        }
    }
    return true;
}

bool Subset::operator!=(const Subset &other) const {
    for (int i = 0; i < 10; i++) {
        if (elements[i] != other.elements[i]) {
            return true;
        }
    }
    return false;
}

void Subset::operator+=(int element) {
    add(element);
}

void Subset::operator-=(int element) {
    remove(element);
}

std::vector <int> Subset::To_vector() const {
    std::vector <int> result;
    for (int i = 0; i < 10; i++) {
        if (elements[i]) {
            result.push_back(i);
        }
    }
    return result;
}