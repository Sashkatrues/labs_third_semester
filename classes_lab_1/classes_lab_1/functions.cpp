#include "class.h"

//Complex::Complex()
//{
//	real = 0.0;
//	imag = 0.0;
//}

Complex::~Complex()
{

}

Complex::Complex(const double r, const double i)
{
	real = r;
	imag = i;
}

Complex::Complex(const Complex& other)
{
	real = other.real;
	imag = other.imag;
}

Complex::Complex(Complex&& other) noexcept {
    real = other.real;
    imag = other.imag;
    other.real = 0.0;
    other.imag = 0.0;
}

Complex& Complex::operator=(const Complex& other)
{
    if (this != &other) {
        real = other.real;
        imag = other.imag;
    }
    return *this;
}

Complex& Complex::operator=(Complex&& other) noexcept {
    if (this != &other) {
        real = other.real;
        imag = other.imag;
        other.real = 0.0;
        other.imag = 0.0;
    }
    return *this;
}

Complex Complex::copy(const Complex& other)
{
    real = other.real;
    imag = other.imag;
    return *this;
}

double Complex::getReal() const {
    return real; 
}

double Complex::getImag() const {
    return imag;
}

void Complex::setReal(double r) {
    real = r;
}

void Complex::setImag(double i) {
    imag = i;
}

Complex Complex::IntToComplex(const double num) const {
    return Complex(num, 0);
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator+(const double num) {
    return *this + IntToComplex(num);
}

Complex operator+(const double lhs, const Complex& rhs) {
    return Complex(lhs + rhs.getReal(), rhs.getImag());
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator-(const double num) {
    return *this - IntToComplex(num);
}

Complex operator-(const double lhs, const Complex& rhs) {
    return Complex(lhs - rhs.getReal(), -rhs.getImag());
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag,
        real * other.imag + imag * other.real);
}

Complex Complex::operator*(const double num) {
    return *this * IntToComplex(num);
}

Complex operator*(const double lhs, const Complex& rhs) {
    return Complex(lhs * rhs.getReal(), lhs * rhs.getImag());
}

Complex Complex::operator/(const Complex& other) const {
    double denom = other.real * other.real + other.imag * other.imag;
    if (denom == 0.0)
    {
        throw std::domain_error("error, denom is 0\n");
    }
    return Complex((real * other.real + imag * other.imag) / denom, (imag * other.real - real * other.imag) / denom);
}

Complex Complex::operator/(const double num) {
    return *this / IntToComplex(num);;
}

Complex operator/(const double lhs, const Complex& rhs) {
    double denom = rhs.getReal() * rhs.getReal() + rhs.getImag() * rhs.getImag();
    if (denom == 0.0)
    {
        throw std::domain_error("error, denom is 0\n");
    }
    return Complex((lhs + rhs.getReal()) / denom, (-lhs * rhs.getImag()) / denom);
}

Complex& Complex::operator+=(const Complex& other) {
    *this = *this + other;
    return *this;
}

Complex Complex::operator+=(const double num){
    return *this += IntToComplex(num);
}

Complex& Complex::operator-=(const Complex& other) {
    *this = *this - other;
    return *this;
}

Complex Complex::operator-=(const double num) {
        return *this -= IntToComplex(num);
}

Complex& Complex::operator*=(const Complex& other) {
    *this = *this * other;
    return *this;
}

Complex Complex::operator*=(const double num) {
    return *this *= IntToComplex(num);
}

Complex& Complex::operator/=(const Complex& other) {
    *this = *this / other;
    return *this;
}

Complex Complex::operator/=(const double num) {
    return *this /= IntToComplex(num);
}

Complex Complex::operator-() const {
    return Complex(-real, -imag);
}

Complex& Complex::operator++() {
    real += 1;
    return(*this);
}

Complex Complex::operator++(int) {
    Complex obj(*this);
    real += 1;
    return obj;
}

Complex& Complex::operator--() {
    real -= 1;
    return(*this);
}

Complex Complex::operator--(int) {
    Complex obj(*this);
    real -= 1;
    return obj;
}

bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

double Complex::abs() const {
    return std::sqrt(real * real + imag * imag);
}

int32_t Complex::CompareAbs(const Complex& other) const {
    double mag1 = abs();
    double mag2 = other.abs();
    if (mag1 < mag2) {
        return -1;
    }
    else if (mag1 > mag2) {
        return 1;
    }
    else {
        return 0;
    }
}

bool Complex::operator<(const Complex& other) const {
    return CompareAbs(other) < 0;
}

bool Complex::operator<=(const Complex& other) const {
    return CompareAbs(other) <= 0;
}

bool Complex::operator>(const Complex& other) const {
    return CompareAbs(other) > 0;
}

bool Complex::operator>=(const Complex& other) const {
    return CompareAbs(other) >= 0;
}

std::ostream& operator<<(std::ostream& fout, const Complex& c) {
    fout << c.real;
    if (c.imag >= 0)
    {
        fout << "+";
    }
    else
    {
        fout << "";
    }
    fout << c.imag << "i";
    return fout;
}

std::istream& operator>>(std::istream& fin, Complex& c) {
    std::cout << "input real complex number: ";
    fin >> c.real;
    std::cout << "input imag complex number: ";
    fin >> c.imag;
    return fin;
}

Complex Complex::conj() const {
    return Complex(real, -imag);
}

double Complex::norm() const {
    return real * real + imag * imag;
}

//double Complex::arg() const {
//    return std::atan2(imag, real);
//}
//
//Complex Complex::pow(double n) const {
//    double r = this->abs();
//    double arg = this->arg();
//    double new_r = std::pow(r, n);
//    double new_arg = n * arg;
//    return Complex(new_r * std::cos(new_arg), new_r * std::sin(new_arg));
//}
//
//Complex Complex::root(int32_t n) const {
//    if (n == 0) {
//        throw std::invalid_argument("Error root 0 dont exist");
//    }
//    double r = this->abs();
//    double arg = this->arg();
//    double new_r = std::pow(r, 1.0 / n);
//    double new_arg = arg / n;
//    return Complex(new_r * std::cos(new_arg), new_r * std::sin(new_arg));
//}
