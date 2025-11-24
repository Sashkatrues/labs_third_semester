#include "linear.h"

Linear::Linear(double c_, double d_) : c(c_), d(d_)
{
	if (c == 0)
	{
		throw std::domain_error("not linear equation, because c = 0");
	}
}

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

void Linear::print(std::ostream& out)
{
	if (c == 0 && d == 0)
	{
		out << "0\n";
		return;
	}
	if (c != 0)
	{
		if (c == 1)
			out << "x";
		else if (c == -1)
			out << "-x";
		else
			out << c << "x";
	}
	if (d != 0)
	{
		out << '+' << d;
	}
	out << '\n';
}

void Linear::solve(std::ostream& out)
{
    if (c == 0)
    {
        throw std::domain_error("error, c is 0");
    }
    double x = -d / c;
    out << "x = " << x << '\n';
}