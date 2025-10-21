#include "class.h"

Complex::Complex()
{
	real = 0.0;
	imag = 0.0;
}

Complex::~Complex()
{

}

Complex::Complex(double r, double i)
{
	real = r;
	imag = i;
}

Complex::Complex(const Complex& other)
{
	real = other.real;
	imag = other.imag;
}

Complex& Complex::operator=(const Complex& other)
{
    if (this != &other) {
        real = other.real;
        imag = other.imag;
    }
    return *this;
}

Complex Complex::copy(const Complex& other)
{
    real = other.real;
    imag = other.imag;
    return *this;
}

Complex Complex::IntToComplex(int32_t num) const {
    return Complex(num, 0);
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator+(int32_t num) {
    return *this + IntToComplex(num);
}

double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }

Complex operator+(int32_t lhs, const Complex& rhs) {
    return Complex(lhs + rhs.getReal(), rhs.getImag());
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator-(int32_t num) {
    return *this - IntToComplex(num);
}

Complex operator-(int32_t lhs, const Complex& rhs) {
    return Complex(lhs - rhs.getReal(), -rhs.getImag());
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag,
        real * other.imag + imag * other.real);
}

Complex Complex::operator*(int32_t num) {
    return *this * IntToComplex(num);
}

Complex operator*(int32_t lhs, const Complex& rhs) {
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

Complex Complex::operator/(int32_t num) {
    return *this / IntToComplex(num);;
}

Complex operator/(int32_t lhs, const Complex& rhs) {
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

Complex Complex::operator+=(int32_t num){
    return *this += IntToComplex(num);
}

Complex& Complex::operator-=(const Complex& other) {
    *this = *this - other;
    return *this;
}

Complex Complex::operator-=(int32_t num) {
        return *this -= IntToComplex(num);
}

Complex& Complex::operator*=(const Complex& other) {
    *this = *this * other;
    return *this;
}

Complex Complex::operator*=(int32_t num) {
    return *this *= IntToComplex(num);
}

Complex& Complex::operator/=(const Complex& other) {
    *this = *this / other;
    return *this;
}

Complex Complex::operator/=(int32_t num) {
    return *this /= IntToComplex(num);
}

Complex Complex::operator-() const {
    return Complex(-real, -imag);
}

bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

double Complex::module() const {
    return std::sqrt(real * real + imag * imag);
}

int32_t Complex::CompareModule(const Complex& other) const {
    double mag1 = module();
    double mag2 = other.module();
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
    return CompareModule(other) < 0;
}

bool Complex::operator<=(const Complex& other) const {
    return CompareModule(other) <= 0;
}

bool Complex::operator>(const Complex& other) const {
    return CompareModule(other) > 0;
}

bool Complex::operator>=(const Complex& other) const {
    return CompareModule(other) >= 0;
}

std::ostream& operator<<(std::ostream& fout, const Complex& c) {
    fout << "(" << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i)";
    return fout;
}

std::istream& operator>>(std::istream& fin, Complex& c) {
    std::cout << "input real complex number: ";
    fin >> c.real;
    std::cout << "input imag complex number: ";
    fin >> c.imag;
    return fin;
}