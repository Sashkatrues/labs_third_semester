#include "second_session.h"

SecondSession::SecondSession(const std::string& name, int course, const int& group, const int& recordBook, const int* grades1, const int* grades2Arr) : FirstSession(name, course, group, recordBook, grades1)
{
    for (int i = 0; i < 5; ++i)
    {
        if (grades2Arr[i] < 0 || grades2Arr[i] > 10)
        {
            throw std::invalid_argument("second session, wrong mark");
        }
        else
        {
            grades2[i] = grades2Arr[i];
        }
    }
}

SecondSession::SecondSession(const SecondSession& other) : FirstSession(other)
{
    for (int i = 0; i < 5; ++i)
    {
        grades2[i] = other.grades2[i];
    }
}

SecondSession::SecondSession(SecondSession&& other) noexcept : FirstSession(std::move(other))
{
    for (int i = 0; i < 5; ++i)
    {
        grades2[i] = other.grades2[i];
    }

    for (int i = 0; i < 5; ++i)
    {
        other.grades2[i] = 0;
    }
}

SecondSession::~SecondSession() {}

SecondSession& SecondSession::operator=(const SecondSession& other)
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

SecondSession& SecondSession::operator=(SecondSession&& other) noexcept
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

int SecondSession::getGrade2(int index) const
{
    return grades2[index];
}
void SecondSession::setGrade2(int index, int value)
{
    if (value < 0 || value > 10)
    {
        throw std::invalid_argument("you input wrong mark");
    }
    else
    {
        grades2[index] = value;
    }
}

double SecondSession::averageGrade() const
{
    double sum = 0;
    for (int i = 0; i < 4; ++i)
    {
        sum += grades[i];
    }
    for (int i = 0; i < 5; ++i)
    {
        sum += grades2[i];
    }
    return sum / 9.0;
}

std::ostream& operator<<(std::ostream& fout, const SecondSession& st) {
    fout << static_cast<const FirstSession&>(st) << ", grades after second session: ";
    for (int i = 0; i < 5; ++i)
    {
        fout << st.grades2[i] << " ";
    }
    return fout;
}