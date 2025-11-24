#include "equation.h"
#include "linear.h"
#include "quadratic.h"

int main()
{
	Linear c(-1, 5);
	Quadratic d(2, 4, 1);
	c.print();
	d.print();
	try
	{
		c.solve();
		d.solve();
	}
	catch (const std::domain_error& e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}