#ifndef EQUATION_H
#define EQUATION_H

#include <iostream>
#include <cmath>

class Equation
{
public:
	virtual void print() = 0;
	virtual void solve() = 0;
};

#endif