#ifndef COURSE_C___SEGMENT_H
#define COURSE_C___SEGMENT_H

#include "interfaces.h"

class Segment: public IFigure {
    static inline const char* name="Segment";
    double weight = 0;
    CVector2D len;

public:
    Segment();
    ~Segment();

    const char *className() override;
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

#endif //COURSE_C___SEGMENT_H
