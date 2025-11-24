#ifndef LINEAR_H
#define LINEAR_H

#include "equation.h"

class Linear : public Equation
{
protected:
	double c;
	double d;
public:
	Linear(double = 0, double = 0);
	~Linear();
	Linear(const Linear&);
	Linear(Linear&&) noexcept;
	Linear& operator =(const Linear&);
	Linear& operator =(Linear&&) noexcept;

	void print(std::ostream&) override;
	void solve(std::ostream&) override;
};

#endif