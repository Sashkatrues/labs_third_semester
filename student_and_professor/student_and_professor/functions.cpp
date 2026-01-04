#include "functions.h"

void showMenu()
{
    std::cout << "menu:\n"
        << "1. input student\n"
        << "2. input professor\n"
        << "3. output list of students\n"
        << "4. output list of professors\n"
        << "5. exit\n"
        << "your choice: ";
}

void addStudent(Person** arr, int& count)
{
    char fullName[100];
    int course, group;
    std::cout << "input full name of student: ";
    std::cin.getline(fullName, 100);
    std::cout << "input course: ";
    std::cin >> course;
    std::cout << "inpute group: ";
    std::cin >> group;
    std::cin.ignore();
    arr[count++] = new Student(fullName, course, group);
}

void addProfessor(Person** arr, int& count)
{
    char fullName[100], dept[100];
    std::cout << "input full name of professor: ";
    std::cin.getline(fullName, 100);
    std::cout << "input department: ";
    std::cin.getline(dept, 100);
    arr[count++] = new Professor(fullName, dept);
}

void printStudents(Person** arr, int count)
{
    if (count == 0)
    {
        std::cout << "no students on the list\n";
    }
    else
    {
        std::cout << "list of students:\n";
        for (int i = 0; i < count; ++i)
        {
            if (arr[i]->isStudent())
            {
                arr[i]->print();
            }
        }
    }
}

void printProfessors(Person** arr, int count)
{
    if (count == 0)
    {
        std::cout << "no professors on the list\n";
    }
    else
    {
        std::cout << "list of professors:\n";
        for (int i = 0; i < count; ++i)
        {
            if (arr[i]->isProfessor())
            {
                arr[i]->print();
            }
        }
    }
}