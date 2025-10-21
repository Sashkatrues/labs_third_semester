#define _CRT_SECURE_NO_WARNINGS
#ifndef CLASS
#define CLASS

#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;
public:
    Complex();
    ~Complex();
    Complex(double r, double i);
    Complex(const Complex& other);

    Complex& operator=(const Complex& other);
    Complex copy(const Complex& other);

    Complex IntToComplex(int32_t num) const;

    Complex operator+(const Complex& other) const;
    Complex operator+(int32_t num);
    friend Complex operator+(int32_t lhs, const Complex& rhs);
    Complex operator-(const Complex& other) const;
    Complex operator-(int32_t num);
    friend Complex operator-(int32_t lhs, const Complex& rhs);
    Complex operator*(const Complex& other) const;
    Complex operator*(int32_t num);
    friend Complex operator*(int32_t lhs, const Complex& rhs);
    Complex operator/(const Complex& other) const;
    Complex operator/(int32_t num);
    friend Complex operator/(int32_t lhs, const Complex& rhs);
    Complex& operator+=(const Complex& other);
    Complex operator+=(int32_t num);
    Complex& operator-=(const Complex& other);
    Complex operator-=(int32_t num);
    Complex& operator*=(const Complex& other);
    Complex operator*=(int32_t num);
    Complex& operator/=(const Complex& other);
    Complex operator/=(int32_t num);

    Complex operator-() const;

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    int32_t CompareModule(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator<=(const Complex& other) const;
    bool operator>(const Complex& other) const;
    bool operator>=(const Complex& other) const;

    double getReal() const;
    double getImag() const;

    friend std::ostream& operator<<(std::ostream& fout, const Complex& c);
    friend std::istream& operator>>(std::istream& fin, Complex& c);

    double module() const;
};

#endif
