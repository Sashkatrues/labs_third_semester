#ifndef FIRST_SESSION_H
#define FIRST_SESSION_H

#include "Student.h"

class FirstSession : public Student
{
protected:
    int grades[4];

public:
    FirstSession() = delete;
    FirstSession(const std::string& name, int course, const int& group, const int& recordBook, const int* grades);
    FirstSession(const FirstSession& other);
    FirstSession(FirstSession&& other) noexcept;
    ~FirstSession();

    FirstSession& operator=(const FirstSession& other);
    FirstSession& operator=(FirstSession&& other) noexcept;

    int getGrade(int index) const;
    void setGrade(int index, int value);

    double averageGrade() const override;

    friend std::ostream& operator<<(std::ostream& fout, const FirstSession& st);
};

#endif