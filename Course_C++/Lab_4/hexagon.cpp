#include "hexagon.h"
#include "interfaces.h"
#include <cmath>

Hexagon::Hexagon() {
    this->Hexagon::initFromDialog();
}
Hexagon::~Hexagon() = default;

const char* Hexagon::className() {
    return name;
}

unsigned int Hexagon::size() {
    return sizeof(*this);
}

double Hexagon::square() {
    return (3 * sqrt(3) * pow(sqrt(pow(A.x, 2) + pow(A.y, 2)), 2)) / 2;
}

double Hexagon::perimeter() {
    return 6 * sqrt(pow(A.x, 2) + pow(A.y, 2));
}

double Hexagon::mass() const {
    return weight;
}

CVector2D Hexagon::position() {
    center.x = (A.x + C.x) / 2;
    center.y = (A.y + C.y) / 2;
    return center;
}

void Hexagon::initFromDialog() {
    std::cout << "Add first point: \n";
    std::cin >> A.x >> A.y;
    std::cout << "Add second point: \n";
    std::cin >> B.x >> B.y;
    std::cout << "Add third point: \n";
    std::cin >> C.x >> C.y;
    std::cout << "Add fourth point: \n";
    std::cin >> D.x >> D.y;
    std::cout << "Add fifth point: \n";
    std::cin >> E.x >> E.y;
    std::cout << "Add sixth point: \n";
    std::cin >> F.x >> F.y;
    std::cout << "Add weight: " << std::endl;
    std::cin >> weight;
}

void Hexagon::draw() {
    std::cout << "Name: " << this->className() << "\n";
    std::cout << "Position: " << "(" << A.x << ", " << A.y << "); "
            << "(" << B.x << ", " << B.y << "); "
            << "(" << C.x << ", " << C.y << "); "
            << "(" << D.x << ", " << D.y << "); "
            << "(" << E.x << ", " << E.y << "); "
            << "(" << F.x << ", " << F.y << "); " << "\n";
    std::cout << "Weight: " << weight << "\n";
    std::cout << "Size: " << size() << "\n";
    std::cout << "Perimeter: " << perimeter() << "\n";
    std::cout << "Square: " << square() << "\n";
}

bool Hexagon::operator<(IPhysObject &obj) const {
    return mass() < obj.mass();
}

bool Hexagon::operator==(IPhysObject &obj) const {
    return mass() == obj.mass();
}