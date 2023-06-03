#ifndef COURSE_C___CLASS_H
#define COURSE_C___CLASS_H

class Vector {
private:

public:
    double x;
    double y;
    double z;

    Vector();
    Vector(double x_, double y_, double z_);
    Vector(const Vector &v);

    double GetX() const;
    double GetY() const;
    double GetZ() const;

    void SetX(double x_);
    void SetY(double y_);
    void SetZ(double z_);

    Vector add(const Vector &other) const;
    Vector sub(const Vector &other) const;
    double len() const;
    double angle(const Vector &other) const;
    void print() const;
};

#endif //COURSE_C___CLASS_H
