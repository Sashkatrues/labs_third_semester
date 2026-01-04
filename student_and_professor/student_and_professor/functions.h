#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "person.h"
#include "student.h"
#include "professor.h"

void showMenu();
void addStudent(Person** arr, int& count);
void addProfessor(Person** arr, int& count);
void printStudents(Person** arr, int count);
void printProfessors(Person** arr, int count);

#endif