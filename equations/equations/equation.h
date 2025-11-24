#ifndef EQUATION_H
#define EQUATION_H

#include <iostream>
#include <fstream>
#include <cmath>

class Equation
{
public:
	virtual void print(std::ostream&) = 0;
	virtual void solve(std::ostream&) = 0;
};

#endif