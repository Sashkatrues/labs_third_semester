#include "class.h"

int main() {
    Complex a(3.0, 4.0);
    Complex b(1.0, -2.0);
    Complex c;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    std::cout << "a + b = " << a + b << "\n";
    std::cout << "a - b = " << a - b << "\n";
    std::cout << "a * b = " << a * b << "\n";
    std::cout << "a / b = " << a / b << "\n";

    std::cout << "a + 2.0 = " << a + 2.0 << "\n";
    std::cout << "2.0 + a = " << 2.0 + a << "\n";
    std::cout << "a - 2.0 = " << a - 2.0 << "\n";
    std::cout << "2.0 - a = " << 2.0 - a << "\n";
    std::cout << "a * 2.0 = " << a * 2.0 << "\n";
    std::cout << "2.0 * a = " << 2.0 * a << "\n";
    std::cout << "a / 2.0 = " << a / 2.0 << "\n";
    std::cout << "2.0 / a = " << 2.0 / a << "\n";

    std::cout << "a == b: " << (a == b) << "\n";
    std::cout << "a != b: " << (a != b) << "\n";
    std::cout << "a < b: " << (a < b) << "\n";
    std::cout << "a <= b: " << (a <= b) << "\n";
    std::cout << "a > b: " << (a > b) << "\n";
    std::cout << "a >= b: " << (a >= b) << "\n";

    std::cout << "-a = " << -a << "\n";
    std::cout << "++a = " << ++a << "\n";
    std::cout << "a++ = " << a++ << "\n";
    std::cout << "--a = " << --a << "\n";
    std::cout << "a-- = " << a-- << "\n";

    a += b;
    std::cout << "a += b: " << a << "\n";
    a -= b;
    std::cout << "a -= b: " << a << "\n";
    a *= b;
    std::cout << "a *= b: " << a << "\n";
    a /= b;
    std::cout << "a /= b: " << a << "\n";

    std::cout << "abs(a) = " << a.abs() << "\n";
    std::cout << "norm(a) = " << a.norm() << "\n";
    std::cout << "conj(a) = " << a.conj() << "\n";

    a.setReal(5.0);
    a.setImag(-3.0);
    std::cout << "a after set: " << a << "\n";
    std::cout << "getReal(a) = " << a.getReal() << "\n";
    std::cout << "getImag(a) = " << a.getImag() << "\n";

    Complex d = a.copy(a);
    std::cout << "copy(a): " << d << "\n";

    Complex e = std::move(b);
    std::cout << "move(b): " << e << "\n";

    Complex f = a.IntToComplex(7.0);
    std::cout << "IntToComplex(7.0): " << f << "\n";

    std::cin >> c;
    std::cout << "c = " << c << "\n";

    return 0;
}
