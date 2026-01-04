#include "functions.h"

int main() 
{
    try
    {
        int grades1[4] = { 10, 8, 9, 10 };
        int grades2[4] = { 5, 6, 7, 8 };

        int gradesSecond1[5] = { 6, 7, 8, 9, 10 };
        int gradesSecond2[5] = { 4, 5, 6, 7, 8 };

        FirstSession st1("Ivanov", 1, 101, 12345, grades1);
        FirstSession st2("Petrov", 1, 101, 12346, grades2);

        SecondSession st3("Sidorov", 2, 202, 22345, grades1, gradesSecond1);
        SecondSession st4("Kuznetsov", 2, 202, 22346, grades2, gradesSecond2);

        std::cout << "first session" << '\n';
        std::cout << "name: " << st1.getName() << '\n';
        std::cout << "course: " << st1.getCourse() << '\n';
        std::cout << "group: " << st1.getGroup() << '\n';
        std::cout << "record book: " << st1.getRecordBook() << '\n';
        std::cout << "id: " << st1.getId() << '\n';
        for (int i = 0; i < 4; ++i)
        {
            std::cout << "mark " << i << ": " << st1.getGrade(i) << '\n';
        }

        std::cout << "\nsecond session" << '\n';
        std::cout << "name: " << st3.getName() << '\n';
        std::cout << "course: " << st3.getCourse() << '\n';
        std::cout << "group: " << st3.getGroup() << '\n';
        std::cout << "record book: " << st3.getRecordBook() << '\n';
        std::cout << "id: " << st3.getId() << '\n';
        for (int i = 0; i < 4; ++i)
        {
            std::cout << "mark first session " << i << ": " << st3.getGrade(i) << '\n';
        }
        for (int i = 0; i < 5; ++i)
        {
            std::cout << "mark second session " << i << ": " << st3.getGrade2(i) << '\n';
        }

        std::cout << "\navarage grade st1: " << st1.averageGrade() << '\n';
        std::cout << "avarage grade st3: " << st3.averageGrade() << '\n';

        FirstSession group1[2] = { st1, st2 };
        SecondSession group2[2] = { st3, st4 };

        std::cout << "\navarage grade group first session: " << averageGroupFirstSession(group1, 2) << '\n';

        std::cout << "avarage grade group second session: " << averageGroupSecondSession(group2, 2) << '\n';
    }
    catch (std::invalid_argument& e) { std::cout << e.what() << '\n'; }
    /*int gradesIvan1[4] = { 10, 9, 10, 10 }; 
    int gradesAnna1[4] = { 6, 8, 7, 9 };
    int gradesPetr1[4] = { 4, 5, 4, 6 };
    FirstSession group1[] = { FirstSession("Ivan", 1, 101, 1001, gradesIvan1), FirstSession("Anna", 1, 101, 1002, gradesAnna1), FirstSession("Peter", 1, 101, 1003, gradesPetr1) };
    int size1 = 3; std::cout << "first session\n"; 
    for (int i = 0; i < size1; ++i)
    {
        std::cout << group1[i] << '\n';
    }
    std::cout << "average grade of the group after the first session: " << averageGroupFirstSession(group1, size1) << '\n';
    int gradesMaria1[4] = {6, 5, 9, 5};
    int gradesSergey1[4] = {5, 10, 8, 9};
    FirstSession group1Extended[] = { group1[0], group1[1], group1[2], FirstSession("Maria", 1, 101, 1004, gradesMaria1), FirstSession("Sergey", 1, 101, 1005, gradesSergey1) };
    int sizeExtended = 5; std::cout << "first session (extended group)\n";
    for (int i = 0; i < sizeExtended; ++i)
    {
        std::cout << group1Extended[i] << '\n';
    }
    std::cout << "average grade of the group after the first session (extended group): " << averageGroupFirstSession(group1Extended, sizeExtended) << '\n';
    int gradesIvan2[5] = {9, 10, 10, 8, 10};
    int gradesAnna2[5] = {7, 9, 9, 8, 10};
    int gradesPetr2[5] = {4, 4, 4, 5, 4};
    int gradesMaria2[5] = {7, 5, 8, 9, 7};
    int gradesSergey2[5] = {8, 8, 8, 7, 9};
    SecondSession group2[] = { SecondSession("Ivan", 1, 101, 1001, gradesIvan1, gradesIvan2), SecondSession("Anna", 1, 101, 1002, gradesAnna1, gradesAnna2), SecondSession("Peter", 1, 101, 1003, gradesPetr1, gradesPetr2), SecondSession("Maria", 1, 101, 1004, gradesMaria1, gradesMaria2), SecondSession("Sergey", 1, 101, 1005, gradesSergey1, gradesSergey2) };
    int size2 = 5;
    std::cout << "end of the year\n";
    for (int i = 0; i < size2; ++i)
    {
        std::cout << group2[i] << '\n';
    }
    std::cout << "average grade of the group for the whole year: " << averageGroupSecondSession(group2, size2) << '\n';*/

    return 0;
}