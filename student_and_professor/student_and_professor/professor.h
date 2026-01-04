#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "person.h"

class Professor : public Person
{
private:
    char* department;
public:
    Professor(const char* f = "", const char* d = "");
    Professor(const Professor& other);
    Professor(Professor&& other) noexcept;
    ~Professor() override;

    Professor& operator=(const Professor& other);
    Professor& operator=(Professor&& other) noexcept;

    void setDepartment(const char* d);
    const char* getDepartment() const;

    void print() const override;
    bool isProfessor() const override;
};

#endif