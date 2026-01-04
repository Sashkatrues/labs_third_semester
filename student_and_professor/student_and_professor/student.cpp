#include "student.h"

Student::Student(const char* f, int c, int g) : Person(f), course(c), group(g) {}

Student::Student(const Student& other) : Person(other), course(other.course), group(other.group) {}

Student::Student(Student&& other) noexcept : Person(std::move(other)), course(other.course), group(other.group)
{
    other.course = 0;
    other.group = 0;
}

Student::~Student() {}

Student& Student::operator=(const Student& other)
{
    if (this != &other)
    {
        Person::operator=(other);
        course = other.course;
        group = other.group;
    }
    return *this;
}

Student& Student::operator=(Student&& other) noexcept
{
    if (this != &other)
    {
        Person::operator=(std::move(other));
        course = other.course;
        group = other.group;
        other.course = 0;
        other.group = 0;
    }
    return *this;
}

void Student::setCourse(int c)
{
    course = c;
}
void Student::setGroup(int g)
{
    group = g;
}

int Student::getCourse() const
{
    return course;
}
int Student::getGroup() const
{
    return group;
}

void Student::print() const
{
    std::cout << "full name: " << fullName << ", course: " << course << ", group: " << group << '\n';
}

bool Student::isStudent() const
{
    return true;
}
