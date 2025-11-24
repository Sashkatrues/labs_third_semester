#include "equation.h"
#include "linear.h"
#include "quadratic.h"

int main()
{
    std::ofstream fout("equations.txt");
    if (!fout.is_open())
    {
        std::cerr << "can't open the fale\n";
        return 1;
    }
    Equation* equations[5];
    try {
        equations[0] = new Linear(2, -4);
        equations[1] = new Linear(-3, 9);
        equations[2] = new Quadratic(1, -3, 2);
        equations[3] = new Quadratic(1, 2, 1);
        equations[4] = new Quadratic(1, 0, 4);
    }
    catch (const std::domain_error& e) {
        std::cout << "error with create equation: " << e.what() << '\n';
        return 1;
    }
    for (int i = 0; i < 5; ++i)
    {
        try {
            fout << "equation: ";
            equations[i]->print(fout);

            fout << "solution: ";
            equations[i]->solve(fout);
        }
        catch (const std::domain_error& e) {
            fout << e.what() << '\n';
        }
        fout << "-----------------------------\n";
    }
    for (int i = 0; i < 5; ++i)
    {
        delete equations[i];
    }

    fout.close();
    return 0;
}