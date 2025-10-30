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
    Complex(const double r, const double i);
    Complex(const Complex& other);
    Complex(Complex&& other) noexcept;

    Complex& operator=(const Complex& other);
    Complex& operator=(Complex&& other) noexcept;
    Complex copy(const Complex& other);

    Complex IntToComplex(const double num) const;

    Complex operator+(const Complex& other) const;
    Complex operator+(const double num);
    friend Complex operator+(const double lhs, const Complex& rhs);

    Complex operator-(const Complex& other) const;
    Complex operator-(const double num);
    friend Complex operator-(const double lhs, const Complex& rhs);

    Complex operator*(const Complex& other) const;
    Complex operator*(const double num);
    friend Complex operator*(const double lhs, const Complex& rhs);

    Complex operator/(const Complex& other) const;
    Complex operator/(const double num);
    friend Complex operator/(const double lhs, const Complex& rhs);

    Complex& operator+=(const Complex& other);
    Complex operator+=(const double num);

    Complex& operator-=(const Complex& other);
    Complex operator-=(const double num);

    Complex& operator*=(const Complex& other);
    Complex operator*=(const double num);

    Complex& operator/=(const Complex& other);
    Complex operator/=(const double num);

    Complex operator-() const;

    Complex& operator++();
    Complex operator++(int);
    Complex& operator--();
    Complex operator--(int);

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    int32_t CompareAbs(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator<=(const Complex& other) const;
    bool operator>(const Complex& other) const;
    bool operator>=(const Complex& other) const;

    double getReal() const;
    double getImag() const;
    void setReal(double r);
    void setImag(double i);

    friend std::ostream& operator<<(std::ostream& fout, const Complex& c);
    friend std::istream& operator>>(std::istream& fin, Complex& c);

    double abs() const;
    Complex conj() const;
    double norm() const;

    //double arg() const;
    //Complex pow(double n) const;
    //Complex root(int32_t n) const;
};

#endif
