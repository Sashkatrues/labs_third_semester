#include "professor.h"

Professor::Professor(const char* f, const char* d) : Person(f)
{
    if(d)
    {
        department = new char[std::strlen(d) + 1];
        std::strcpy(department, d);
    }
    else
    {
         department = nullptr;
    }
}

Professor::Professor(const Professor& other) : Person(other)
{
    if (other.department)
    {
        department = new char[strlen(other.department) + 1];
        strcpy(department, other.department);
    }
    else
    {
        department = nullptr;
    }
}

Professor::Professor(Professor&& other) noexcept : Person(std::move(other))
{
    department = other.department;
    other.department = nullptr;
}

Professor::~Professor()
{
    delete[] department;
}

Professor& Professor::operator=(const Professor& other)
{
    if (this != &other)
    {
        Person::operator=(other);
        delete[] department;
        if (other.department)
        {
            department = new char[strlen(other.department) + 1];
            strcpy(department, other.department);
        }
        else
        {
            department = nullptr;
        }
    }
    return *this;
}

Professor& Professor::operator=(Professor&& other) noexcept
{
    if (this != &other)
    {
        Person::operator=(std::move(other));
        delete[] department;
        department = other.department;
        other.department = nullptr;
    }
    return *this;
}

void Professor::setDepartment(const char* d)
{
    delete[] department;
    if (d)
    {
        department = new char[std::strlen(d) + 1];
        std::strcpy(department, d);
    }
    else
    {
        department = nullptr;
    }
}

const char* Professor::getDepartment() const
{
    return department;
}

void Professor::print() const
{
    std::cout << "full name: " << fullName << ", department: " << department << '\n';
}

bool Professor::isProfessor() const
{
    return true;
}