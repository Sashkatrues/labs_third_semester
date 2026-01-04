#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student
{
protected:
    const int id;
    std::string name;
    int course;
    int group;
    const int recordBook;

    static int nextId;

public:
    Student() = delete;
    Student(const std::string& name, int course, const int& group, const int& recordBook);
    Student(const Student& other);
    Student(Student&& other) noexcept;
    ~Student();

    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;

    void setName(const std::string& n);
    void setCourse(int c);
    void setGroup(const int& g);

    std::string getName() const;
    int getCourse() const;
    int getGroup() const;
    int getRecordBook() const;
    int getId() const;
    
    virtual double averageGrade() const = 0;

    friend std::ostream& operator<<(std::ostream& fout, const Student& st);
};

#endif