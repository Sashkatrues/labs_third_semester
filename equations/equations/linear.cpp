#include "linear.h"

Linear::Linear(double c_, double d_) : c(c_), d(d_) {}

Linear::~Linear() {}

Linear::Linear(const Linear& other) : c(other.c), d(other.d) {}

Linear::Linear(Linear&& other) noexcept : c(other.c), d(other.d)
{
    other.c = 0;
    other.d = 0;
}

Linear& Linear::operator=(const Linear& other)
{
	if (this != &other)
	{
		c = other.c;
		d = other.d;
	}
	return *this;
}

Linear& Linear::operator=(Linear&& other) noexcept
{
	if (this != &other)
	{
		c = other.c;
		d = other.d;
		other.c = 0;
		other.d = 0;
	}
	return *this;
}

void Linear::print()
{
	if (c == 0 && d == 0)
	{
		std::cout << "0\n";
		return;
	}
	if (c != 0)
	{
		if (c == 1)
			std::cout << "x";
		else if (c == -1)
			std::cout << "-x";
		else
			std::cout << c << "x";
	}
	if (d != 0)
	{
		std::cout << '+' << d;
	}
	std::cout << '\n';
}

void Linear::solve()
{
    if (c == 0)
    {
        throw std::domain_error("error, c is 0");
    }
    double x = -d / c;
    std::cout << "x = " << x << '\n';
}