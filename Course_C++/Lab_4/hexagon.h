#ifndef COURSE_C___HEXAGON_H
#define COURSE_C___HEXAGON_H

#include "interfaces.h"

class Hexagon: public IFigure {
private:
    static inline const char* name = "Hexagon";
    CVector2D A;
    CVector2D B;
    CVector2D C;
    CVector2D D;
    CVector2D E;
    CVector2D F;
    CVector2D center;
    double weight = 0;

public:
    Hexagon();
    ~Hexagon();
    const char* className() override;
    unsigned int size() override;
    double square() override;
    double perimeter() override;
    double mass() const override;
    CVector2D position() override;
    void initFromDialog() override;
    void draw() override;
    bool operator==(IPhysObject &obj) const override;
    bool operator<(IPhysObject &obj) const override;
};

#endif //COURSE_C___HEXAGON_H
