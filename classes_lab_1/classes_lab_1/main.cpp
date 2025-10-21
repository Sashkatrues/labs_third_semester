#include "class.h"

int main() {
    Complex a(3, 4), b(1, -2);
    try {
        Complex c = a / b;
        std::cout << "a / b = " << c << '\n';
        //a /= b;
        std::cout << "a = " << a << '\n';
    }
    catch (std::domain_error& m) { std::cout << "error: " << m.what() << '\n'; }
    std::cout << "-a = " << -a << '\n';
    //b = a;
    if(a > b)
    {
        std::cout << "a != b" << '\n';
    }
    std::cout << "3+b= " << 3 + b << '\n';
    
    Complex d;
    std::cin >> d;
    std::cout << "you inputted: " << d << '\n';
    
    std::cout << "module d: " << d.module() << '\n';

    return 0;
}
