#include "exception.h"
#include "template.h"
#include <iostream>

int main() {
    int a[5] = {1, 2, 3, 4};
    std::cout << findMax<int>(a, 5);
//try {
//    std::cout << findMax<int>(a, 0);
//} catch (Exception& e) {
//    std::cerr << "Error: " << e.what() << '\n';
//}


    Array<int, 5> arr(5);
    try {
        std::cout << arr[8];
    } catch (Exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}