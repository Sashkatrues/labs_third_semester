#include "deque.h"

void PrintInt(int x)
{
    std::cout << x << " ";
}

void PrintStr(char* s)
{
    std::cout << s << " ";
}

void ToUpper(char*& s)
{
    for (int i = 0; s[i]; ++i)
        s[i] = std::toupper(s[i]);
}