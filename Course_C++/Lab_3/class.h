#ifndef COURSE_C___CLASS_H
#define COURSE_C___CLASS_H

#include <iostream>
#include <vector>

struct Point {
    double x;
    double y;
};

/* TRIANGLE */
class Triangle {
private:
    std::vector <Point> points; // points representing the triangle vertices

public:
    Triangle(std::vector <Point> points);

    Point getVertex1() const;
    Point getVertex2() const;
    Point getVertex3() const;

    double area() const;
    void move(std::vector <double> &vector);

    bool operator==(const Triangle &other) const;
    bool operator!=(const Triangle &other) const;
    bool operator<(const Triangle &other) const;
    bool operator>(const Triangle &other) const;
    void operator+(std::vector <double> &vector);

private:
    static double distance(const Point &point1, const Point &point2) ;
};

/* SUBSET */
class Subset {
private:
    bool elements[10];

public:
    Subset();
    Subset(const std::vector <int> &elements);

    void add(int element);
    void remove(int element);

    Subset operator+(const Subset &other) const;

    bool operator==(const Subset &other) const;
    bool operator!=(const Subset &other) const;

    void operator+=(int element);
    void operator-=(int element);

    std::vector <int> To_vector() const;
};

#endif //COURSE_C___CLASS_H
