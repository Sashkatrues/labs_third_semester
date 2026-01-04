#include "first_session.h"

FirstSession::FirstSession(const std::string& name, int course, const int& group, const int& recordBook, const int* gradesArr) : Student(name, course, group, recordBook)
{
    for (int i = 0; i < 4; ++i)
    {
        if (gradesArr[i] < 0 || gradesArr[i] > 10)
        {
            throw std::invalid_argument("first session, wrong mark");
        }
        else
        {
            grades[i] = gradesArr[i];
        }
    }
}

FirstSession::FirstSession(const FirstSession& other) : Student(other)
{
    for (int i = 0; i < 4; ++i)
    {
            grades[i] = other.grades[i];
    }
}

FirstSession::FirstSession(FirstSession&& other) noexcept : Student(std::move(other))
{
    for (int i = 0; i < 4; ++i)
    {
        grades[i] = other.grades[i];
    }
    for (int i = 0; i < 4; ++i)
    {
        other.grades[i] = 0;
    }
}

FirstSession::~FirstSession() {}

FirstSession& FirstSession::operator=(const FirstSession& other)
{
    if (this != &other)
    {
        name = other.name;
        course = other.course;
        group = other.group;
        for (int i = 0; i < 4; ++i)
        {
            grades[i] = other.grades[i];
        }
    }
    return *this;
}

FirstSession& FirstSession::operator=(FirstSession&& other) noexcept
{
    if (this != &other)
    {
        name = std::move(other.name);
        course = other.course;
        group = other.group;
        for (int i = 0; i < 4; ++i)
        {
            grades[i] = other.grades[i];
        }
        for (int i = 0; i < 4; ++i)
        {
            other.grades[i] = 0;
        }
    }
    return *this;
}


int FirstSession::getGrade(int index) const
{
    return grades[index];
}

void FirstSession::setGrade(int index, int value)
{
    if (value < 0 || value > 10)
    {
        throw std::invalid_argument("you input wrong mark");
    }
    else
    {
        grades[index] = value;
    }
}

double FirstSession::averageGrade() const
{
    double sum = 0;
    for (int i = 0; i < 4; ++i)
    {
        sum += grades[i];
    }
    return sum / 4.0;
}

std::ostream& operator<<(std::ostream& fout, const FirstSession& st)
{
    fout << static_cast<const Student&>(st) << ", grades after first session: ";
    for (int i = 0; i < 4; ++i)
    {
        fout << st.grades[i] << " ";
    }
    return fout;
}