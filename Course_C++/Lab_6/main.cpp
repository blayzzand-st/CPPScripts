#include <iostream>
#include <vector>
#include "functions.h"

int main() {
    std::vector <int> numbers1 = {1, 2, 3, 4, 5};
    std::vector <int> numbers2 = {-1, 2, 3, 4, 5};
    std::vector <int> numbers3 = {6, 2, 3, 4, 5};

    CPoint targetPoint = {1, 0};

    std::vector <CPoint> custom_vector1 = {{1, 0}, {2, 0}, {3, 0}};
    std::vector <CPoint> custom_vector2 = {{0, 0}, {2, 0}, {3, 0}};
    std::vector <CPoint> custom_vector3 = {{6, 0}, {2, 0}, {3, 0}};

    auto it1 = find_not_custom(numbers1.begin(), numbers1.end(), 1);
    auto it2 = find_not_custom(custom_vector1.begin(), custom_vector1.end(), targetPoint);

    std::cout << std::boolalpha;
    std::cout << none_of_custom(numbers1.begin(), numbers1.end(), is_negative) << "\n";
    std::cout << none_of_custom(numbers2.begin(), numbers1.end(), is_negative) << "\n";

    std::cout << is_sorted_custom(numbers1.begin(), numbers1.end(), std::less<int>()) << "\n";
    std::cout << is_sorted_custom(numbers3.begin(), numbers1.end(), std::less<int>()) << "\n";

    std::cout << *it1 << '\n';

    std::cout << "-------------" << std::endl;
    std::cout << "CUSTOM VALUE:\n";
    std::cout << "-------------" << std::endl;

    std::cout << none_of_custom(custom_vector1.begin(), custom_vector1.end(), is_origin) << "\n";
    std::cout << none_of_custom(custom_vector2.begin(), custom_vector2.end(), is_origin) << "\n";

    std::cout << is_sorted_custom(custom_vector1.begin(), custom_vector1.end(), lessThanByX) << "\n";
    std::cout << is_sorted_custom(custom_vector3.begin(), custom_vector3.end(), lessThanByX) << std::endl;
    std::cout << "{" << it2->x << ", " << it2->y << "}\n";

    return 0;
}