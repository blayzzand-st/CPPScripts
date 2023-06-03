#include <iostream>
#include "class.h"

int main() {
    Point a = {0.0, 4.0};
    Point b = {-2.0, 0.0};
    Point c = {2.0, 0.0};
    Point a1 = {2.0, 3.0};
    std::vector <Point> vertices {a, b, c};
    std::vector <Point> vertices1 {a1, b, c};
    std::vector <double> to_move {1.0, 0.0};

    Triangle triangle(vertices);
    Triangle triangle1(vertices1);

    Subset subset({1, 2, 3});
    Subset subset1({4, 5, 6});

    std::cout << "Diff " << (triangle != triangle1) << "\n";
    std::cout << "Same  " << (triangle == triangle) << "\n";
    std::cout << "More  " << (triangle > triangle1) << "\n";
    std::cout << "Less  " << (triangle1 < triangle) << "\n";

    triangle + to_move;

    std::cout << "New: \n";
    std::cout << triangle.getVertex1().x << " " << triangle.getVertex1().y << "\n";
    std::cout << triangle.getVertex2().x << " " << triangle.getVertex2().y << "\n";
    std::cout << triangle.getVertex3().x << " " << triangle.getVertex3().y << "\n";

    std::cout << "Subsets: \n";
    for (auto i : (subset + subset1).To_vector()) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << "Same " << (subset == subset) << "\n";
    std::cout << "Diff " << (subset != subset1) << "\n";
    std::cout << "First add: 4 \n";
    subset += 4;
    for (auto i : subset.To_vector()) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "First remove: 2 \n";
    subset -= 2;
    for (auto i : subset.To_vector()) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}