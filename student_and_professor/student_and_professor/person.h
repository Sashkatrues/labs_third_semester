#ifndef PERSON_H
#define PERSON_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

class Person
{
protected:
    char* fullName;
public:
    Person(const char* f = "");
    Person(const Person& other);
    Person(Person&& other) noexcept;
    virtual ~Person();

    Person& operator=(const Person& other);
    Person& operator=(Person&& other) noexcept;

    void setFio(const char* f);
    const char* getFio() const;

    virtual void print() const;
    virtual bool isStudent() const;
    virtual bool isProfessor() const;
};

#endif