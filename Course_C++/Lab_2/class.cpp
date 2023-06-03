#include <iostream>
#include <cmath>
#include "class.h"

Vector::Vector() {                              // default constructor
    x = 0;
    y = 0;
    z = 0;
}

Vector::Vector(double x_, double y_, double z_) { // float constructor
    x = x_;
    y = y_;
    z = z_;
}

Vector::Vector(const Vector &v) {              // copy constructor
    x = v.x;
    y = v.y;
    z = v.z;
}

double Vector::GetX() const {                          // Getters
    return x;
}

double Vector::GetY() const {
    return y;
}

double Vector::GetZ() const {
    return z;
}

void Vector::SetX(double x_) {                   // Setters
    x = x_;
}

void Vector::SetY(double y_) {
    y = y_;
}

void Vector::SetZ(double z_) {
    z = z_;
}

Vector Vector::add(const Vector &other) const {  // Functionality
    return {x + other.x, y + other.y, z + other.z};
}

Vector Vector::sub(const Vector &other) const {
    return {x - other.x, y - other.y, z - other.z};
}

double Vector::len() const {
    return (sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2))));
}

double Vector::angle(const Vector &other) const {
    return acos((x * other.x + y * other.y + z * other.z) /
                ((sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)))) *
                 sqrt((pow(other.x, 2) + pow(other.y, 2) + pow(other.z, 2)))));
}

void Vector::print() const {
    std::cout << "Vector: (" << x << ", " << y << ", " << z << ")\n";
}