#include "quadratic.h"

Quadratic::Quadratic(double c_, double d_, double e_) : c(c_), d(d_), e(e_) {}

Quadratic::~Quadratic() {}

Quadratic::Quadratic(const Quadratic& other) : c(other.c), d(other.d), e(other.e) {}

Quadratic::Quadratic(Quadratic&& other) noexcept : c(other.c), d(other.d), e(other.e)
{
	other.c = 0;
	other.d = 0;
	other.e = 0;
}

Quadratic& Quadratic::operator=(const Quadratic& other)
{
	if (this != &other)
	{
		c = other.c;
		d = other.d;
		e = other.e;
	}
	return *this;
}

Quadratic& Quadratic::operator=(Quadratic&& other) noexcept
{
	if (this != &other)
	{
		c = other.c;
		d = other.d;
		e = other.e;
		other.c = 0;
		other.d = 0;
		other.e = 0;
	}
	return *this;
}

void Quadratic::print()
{
	if (c == 0 && d == 0 && e == 0)
	{
		std::cout << "0\n";
		return;
	}
	if (c != 0)
	{
		if (c == 1)
			std::cout << "x^2";
		else if (c == -1)
			std::cout << "-x^2";
		else
			std::cout << c << "x^2";
	}
	if (d != 0)
	{
		if (d == 1)
			std::cout << "+x";
		else if (d == -1)
			std::cout << "-x";
		else
			std::cout << '+' << d << "x";
	}
	if (e != 0)
	{
		std::cout << '+' << e;
	}
	std::cout << '\n';
}

void Quadratic::solve()
{
	if (c == 0)
	{
		throw std::domain_error("error, c is 0");
	}
	double D = (d * d) - (4 * c * e);
	if (D < 0)
	{
		throw std::domain_error("error, D < 0");
	}
	else if (D == 0)
	{
		double x = -d / (2 * c);
		std::cout << "x = " << x << '\n';
	}
	else
	{
		double x1 = (-d + std::sqrt(D)) / (2 * c);
		double x2 = (-d - std::sqrt(D)) / (2 * c);
		std::cout << "x1 = " << x1 << "; x2 = " << x2 << '\n';
	}
}