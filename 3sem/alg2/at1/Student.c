#include <stdlib.h>
#include "Student.h"
#include <stdio.h>

struct student {
  int nusp;
  char name[50];
  char course[50];
  float grade;
};

long sumOfEachTypeOfStruct() {
  return sizeof(int) + sizeof(float) + sizeof(char) * 50 * 2;
}

void printStudent(const STUDENT *s) {
  printf("nUSP: %d\n",   s->nusp);
  printf("Nome: %s\n",   s->name);
  printf("Curso: %s\n",  s->course);
  printf("Nota: %.2f\n", s->grade);
}