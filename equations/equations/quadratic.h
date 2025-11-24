#ifndef QUADRATIC_H
#define QUADRATIC_H

#include "linear.h"

class Quadratic : public Equation
{
private:
	double c;
	double d;
	double e;
public:
	Quadratic(double = 0, double = 0, double = 0);
	~Quadratic();
	Quadratic(const Quadratic&);
	Quadratic(Quadratic&&) noexcept;
	Quadratic& operator =(const Quadratic&);
	Quadratic& operator =(Quadratic&&) noexcept;

	void print(std::ostream&) override;
	void solve(std::ostream&) override;
};
#endif