#include "person.h"

Person::Person(const char* f)
{
    fullName = new char[strlen(f) + 1];
    std::strcpy(fullName, f);
}

Person::Person(const Person& other)
{
    fullName = new char[std::strlen(other.fullName) + 1];
    std::strcpy(fullName, other.fullName);
}

Person::Person(Person&& other) noexcept
{
    fullName = other.fullName;
    other.fullName = nullptr;
}

Person::~Person()
{
    delete[] fullName;
}

Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        delete[] fullName;
        fullName = new char[std::strlen(other.fullName) + 1];
        std::strcpy(fullName, other.fullName);
    }
    return *this;
}

Person& Person::operator=(Person&& other) noexcept
{
    if (this != &other)
    {
        delete[] fullName;
        fullName = other.fullName;
        other.fullName = nullptr;
    }
    return *this;
}


void Person::setFio(const char* f)
{
    delete[] fullName;
    fullName = new char[std::strlen(f) + 1];
    std::strcpy(fullName, f);
}

const char* Person::getFio() const
{
    return fullName;
}

void Person::print() const
{
    std::cout << "full name: " << fullName << '\n';
}

bool Person::isStudent() const
{
    return false;
}

bool Person::isProfessor() const
{
    return false;
}
