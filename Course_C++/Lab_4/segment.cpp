#include "interfaces.h"
#include "segment.h"
#include <cmath>

Segment::Segment() {
    this->Segment::initFromDialog();
}

Segment::~Segment() = default;

const char* Segment::className() {
    return name;
}

unsigned int Segment::size() {
    return sizeof(*this);
}

double Segment::square() {
    return 0;
}

double Segment::perimeter() {
    return sqrt(pow(len.x, 2) + pow(len.y, 2));
}

double Segment::mass() const {
    return weight;
}

CVector2D Segment::position() {
    return len;
}

void Segment::initFromDialog() {
    std::cout << "Enter the vector, that describe your segment: " << std::endl;
    std::cin >> len.x >> len.y;
    std::cout << "Add weight: " << std::endl;
    std::cin >> weight;
}

void Segment::draw() {
    std::cout << "Name: " << this->className() << "\n";
    std::cout << "Position: " << this->len.x << ' ' << this->len.y << "\n";
    std::cout << "Length: " << perimeter() << "\n";
    std::cout << "Weight: " << weight << "\n";
    std::cout << "Size: " << size() << "\n";
}

bool Segment::operator==(IPhysObject &obj) const {
    return mass() == obj.mass();
}

bool Segment::operator<(IPhysObject &obj) const {
    return mass() < obj.mass();
}