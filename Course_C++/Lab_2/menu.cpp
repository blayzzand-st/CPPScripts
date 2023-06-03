#include <iostream>
#include "class.h"
#include "menu.h"

void Menu::create(Vector &vector) {
    std::cout << "Input x, y, z \n";
    int x, y, z;
    std::cin >> x >> y >> z;
    Vector vector_new(x, y, z);
    vector = vector_new;
    std::cout << "Vector created! \n";
}

void Menu::sum(Vector &vector) {
    std::cout << "Input x, y, z \n";
    int x, y, z;
    std::cin >> x >> y >> z;
    Vector vector_to_sum(x, y, z);
    vector = vector.add(vector_to_sum);
    std::cout << "Operation complete!" << "\n";
}

void Menu::sub(Vector &vector) {
    std::cout << "Input x, y, z \n";
    int x, y, z;
    std::cin >> x >> y >> z;
    Vector vector_to_sub(x, y, z);
    vector = vector.sub(vector_to_sub);
    std::cout << "Operation complete!" << "\n";
}

void Menu::angle(Vector &vector) {
    std::cout << "Input x, y, z \n";
    int x, y, z;
    std::cin >> x >> y >> z;
    Vector angle_vector(x, y, z);
    std::cout << "Vector angle: " << vector.angle(angle_vector) << "\n";
}

void Menu::len(Vector &vector) {
    std::cout << "Vector length: " << vector.len() << "\n";
}

void Menu::output(Vector &vector) {
    vector.print();
}