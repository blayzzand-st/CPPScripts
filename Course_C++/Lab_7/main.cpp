#include <iostream>
#include "ringBuffer.h"

int main() {
    RingBuffer<int> buffer(4);
    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);
    buffer.pop_back();      // 1 2
    buffer.pop_front();     // 2
    buffer.push_front(3);       // 3 2

    RingBuffer<int>::Iterator it = buffer.begin() + 1;
    it = buffer.insert(it, 9);     // 3 9 2

    it = buffer.begin() + 2;
    it = buffer.erase(it);      // 3 9

    buffer.push_back(1);
    std::cout << buffer[0] << "\n";


    for (int & el : buffer) {
        std::cout << el << " ";
    }

    return 0;
}