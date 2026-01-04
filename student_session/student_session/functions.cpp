#include "functions.h"

double averageGroupFirstSession(FirstSession* group, int size)
{
    double sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += group[i].averageGrade();
    }
    return sum / size;
}

double averageGroupSecondSession(SecondSession* group, int size)
{
    double sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += group[i].averageGrade();
    }
    return sum / size;
}