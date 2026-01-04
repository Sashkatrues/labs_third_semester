#include "student.h"

int Student::nextId = 1;

Student::Student(const std::string& name, int course, const int& group, const int& recordBook) : id(nextId++), name(name), course(course), group(group), recordBook(recordBook) {}

Student::Student(const Student& other) : id(nextId++), name(other.name), course(other.course), group(other.group), recordBook(other.recordBook) {}

Student::Student(Student&& other) noexcept : id(nextId++), name(std::move(other.name)), course(other.course), group(other.group), recordBook(other.recordBook)
{
    other.course = 0;
    other.group = 0;
    other.name.clear();
}

Student::~Student() {}

void Student::setName(const std::string& n)
{
    name = n;
}

Student& Student::operator=(const Student& other)
{
    if (this != &other)
    {
        name = other.name;
        course = other.course;
        group = other.group;
    }
    return *this;
}

Student& Student::operator=(Student&& other) noexcept
{
    if (this != &other)
    {
        name = std::move(other.name);
        course = other.course;
        group = other.group;
    }
    return *this;
}

void Student::setCourse(int c)
{
    course = c;
}

void Student::setGroup(const int& g)
{
    group = g;
}

std::string Student::getName() const
{
    return name;
}

int Student::getCourse() const
{
    return course;
}

int Student::getGroup() const
{
    return group;
}

int Student::getRecordBook() const
{
    return recordBook;
}

int Student::getId() const
{
    return id;
}

std::ostream& operator<<(std::ostream& fout, const Student& st)
{
    fout << "id: " << st.id << ", name: " << st.name << ", course: " << st.course << ", group: " << st.group << ", recordBook: " << st.recordBook;
    return fout;
}