#include "deque.h"

int main() {
    TDeque<int> intDeque;
    intDeque.InsRear(10);
    intDeque.InsFront(5);
    intDeque.InsRear(20);
    std::cout << "int deque: ";
    intDeque.Browse(PrintInt);
    std::cout << '\n';

    TDeque<char*> strDeque;

    char* str1 = new char[6];
    std::strcpy(str1, "hello");

    char* str2 = new char[6];
    std::strcpy(str2, "world");

    strDeque.InsRear(str1);
    strDeque.InsFront(str2);

    std::cout << "before transformation: ";
    strDeque.Browse(PrintStr);
    std::cout << std::endl;

    strDeque.Browse(ToUpper);

    std::cout << "after: ";
    strDeque.Browse(PrintStr);
    std::cout << std::endl;

    delete[] str1;
    delete[] str2;

    return 0;
}