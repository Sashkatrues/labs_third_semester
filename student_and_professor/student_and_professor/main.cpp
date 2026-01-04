#include "functions.h"

int main()
{
    const int MAX = 100;
    Person* arr[MAX];
    int count = 0;

    int choice{};
    try
    {
        do
        {
            showMenu();
            std::cin >> choice;
            std::cin.ignore();
            switch (choice)
            {
                case 1:
                {
                    addStudent(arr, count);
                    break;
                }
                case 2:
                {
                    addProfessor(arr, count);
                    break;
                }
                case 3:
                {
                    printStudents(arr, count);
                    break;
                }
                case 4:
                {
                    printProfessors(arr, count);
                    break;
                }
                default:
                {
                    throw std::invalid_argument("bad choice");
                }
            }
        } while (choice != 5);
    }
    catch (std::invalid_argument& e) { std::cout << e.what(); }

    for (int i = 0; i < count; ++i)
    {
        delete arr[i];
    }

    return 0;
}