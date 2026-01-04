#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : public Person
{
private:
    int course;
    int group;
public:
    Student(const char* f = "", int c = 0, int g = 0);
    Student(const Student& other);
    Student(Student&& other) noexcept;
    ~Student() override;

    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;

    void setCourse(int c);
    void setGroup(int g);

    int getCourse() const;
    int getGroup() const;

    void print() const override;
    bool isStudent() const override;
};

#endif