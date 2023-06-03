#include <iostream>
#include "class.h"
#include "menu.h"

int main() {
    std::string command;
    Vector vector(1, 2, 3);

    std::cout << "1 - create \n2 - length \n3 - add \n4 - sub \n5 - angle \n6 - print \n";

    while (true) {
        std::cin >> command;
        Menu menu;

        if (command == "1") {
            menu.create(vector);
            continue;
        }
        else if (command == "2") {
            menu.len(vector);
            continue;
        }
        else if (command == "3") {
            menu.sum(vector);
            continue;
        }
        else if (command == "4") {
            menu.sub(vector);
            continue;
        }
        else if (command == "5") {
            menu.sub(vector);
            continue;
        }
        else if (command == "6") {
            menu.output(vector);
            continue;
        }
    }
}