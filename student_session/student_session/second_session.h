#ifndef SECOND_SESSION_H
#define SECOND_SESSION_H

#include "first_session.h"

class SecondSession : public FirstSession
{
    int grades2[5];

public:
    SecondSession() = delete;
    SecondSession(const std::string& name, int course, const int& group, const int& recordBook, const int* grades1, const int* grades2);
    SecondSession(const SecondSession& other);
    SecondSession(SecondSession&& other) noexcept;
    ~SecondSession();

    SecondSession& operator=(const SecondSession& other);
    SecondSession& operator=(SecondSession&& other) noexcept;

    int getGrade2(int index) const;
    void setGrade2(int index, int value);

    double averageGrade() const override;

    friend std::ostream& operator<<(std::ostream& fout, const SecondSession& st);
};

#endif