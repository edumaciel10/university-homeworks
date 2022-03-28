#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"
char *readLine()
{
    char *string = NULL;
    char currentInput;
    int index = 0;
    do
    {
        currentInput = (char)getchar();
        string = (char *)realloc(string, sizeof(char) * (index + 1));
        string[index] = currentInput;
        index++;
        if (currentInput == '\r')
        {
            currentInput = (char)getchar();
        }
    } while ((currentInput != '\n') && (currentInput != EOF));
    string[index - 1] = '\0';
    return string;
}

long sumOfSizeOfStruct() {
  return sizeof(int) + sizeof(float) + sizeof(char) * 50 * 2;
}

int countOfElementsOnFile(FILE* arq) {
    fseek(arq, 0, SEEK_END);
    long size = ftell(arq);
    long sizeStruct = sumOfSizeOfStruct();
    fseek(arq, 0, SEEK_SET);
    return (int)size/sizeStruct;
}


int fsize(FILE* arq) {
    fseek(arq, 0, SEEK_END);
    long size = ftell(arq);
    fseek(arq, 0, SEEK_SET);
    return (int)size;
}

struct student {
  int nusp;
  char name[50];
  char course[50];
  float grade;
};

void checkIfNeedToPrintSeparator(int isEndOfFile, int index, int finalIndex) {
  if(!isEndOfFile && index <= finalIndex && index != 0) {
    printf("\n");
  }
}
void readAndShowAllStudents(FILE *arq) {
  int countOfElements = countOfElementsOnFile(arq);
  struct student *students = (struct student *)malloc(sizeof(struct student) * countOfElements); // can be createStudentsStruct(size);
  fseek(arq, 0, SEEK_SET);
  int i=0;

  do {
    fread(&students[i].nusp  , sizeof(int  )     , 1, arq);
    fread(&students[i].name  , sizeof(char ) * 50, 1, arq);
    fread(&students[i].course, sizeof(char ) * 50, 1, arq);
    fread(&students[i].grade , sizeof(float)     , 1, arq);
    printStudent(&students[i]);
    i++;
    // printf("\n Condition: %d %d", !feof(arq), (i < interval));
    checkIfNeedToPrintSeparator(feof(arq), i+1, countOfElements);
  } while(!feof(arq) && (i < countOfElements ));

  free(students);
}

void readAndShowStartToMiddleStudents(FILE *arq) {
  int countOfElements = countOfElementsOnFile(arq)/2;
  struct student *students = (struct student *)malloc(sizeof(struct student) * countOfElements);
  int i= 0;

  do {
    fread(&students[i].nusp  , sizeof(int  )     , 1, arq);
    fread(&students[i].name  , sizeof(char ) * 50, 1, arq);
    fread(&students[i].course, sizeof(char ) * 50, 1, arq);
    fread(&students[i].grade , sizeof(float)     , 1, arq);
    printStudent(&students[i]);
    i++;
    // printf("\n Condition: %d %d", !feof(arq), (i < interval));
    checkIfNeedToPrintSeparator(feof(arq), i+1, countOfElements);
  } while(!feof(arq) && (i < countOfElements ));

  free(students);
}

void readAndShowMiddleToEndStudents(FILE *arq) {
  int countOfElements = countOfElementsOnFile(arq)/2;
  int fileSizeOfHalf = fsize(arq);
  struct student *students = (struct student *)malloc(sizeof(struct student) * countOfElements);
  int i= 0;
  fseek(arq, fileSizeOfHalf/2, SEEK_SET);

  do {
    fread(&students[i].nusp  , sizeof(int  )     , 1, arq);
    fread(&students[i].name  , sizeof(char ) * 50, 1, arq);
    fread(&students[i].course, sizeof(char ) * 50, 1, arq);
    fread(&students[i].grade , sizeof(float)     , 1, arq);
    printStudent(&students[i]);
    i++;
    // printf("\n Condition: %d %d", !feof(arq), (i < interval));
    checkIfNeedToPrintSeparator(feof(arq), i+1, countOfElements);
  } while(!feof(arq) && (i < countOfElements ));

  free(students);
}


void readAndShowTheIntervalOfStudents(FILE *arq) {
  int start = 0;
  int end = 0;
  scanf("%d %d", &start, &end);
  int interval = end - start;

  // int countOfElements = countOfElementsOnFile(arq);
  long sizeOfEachStruct = sumOfSizeOfStruct();

  long sizeOfStart = sizeOfEachStruct * (start-1);
  fseek(arq, sizeOfStart, SEEK_SET);
  // aqui eu decidi por alocar apenas o pedaço de uma struct por conta do escopo do projeto
  // se eu tivesse que fazer mais operações com as structs lidas eu faria um **, mas como não é o caso, apenas 1 struct serve bem
  // allocate a one STUDENT struct
  STUDENT *student = (STUDENT *)malloc(sizeof(STUDENT));
  int i = 0;

  do {
    fread(&student->nusp  , sizeof(int  )     , 1, arq);
    fread(&student->name  , sizeof(char ) * 50, 1, arq);
    fread(&student->course, sizeof(char ) * 50, 1, arq);
    fread(&student->grade , sizeof(float)     , 1, arq);
    // printf(" i: %d \n", i);
    if(feof(arq)) {
      break;
    }

    checkIfNeedToPrintSeparator(feof(arq), i, interval);
    i++;
    printStudent(student);
    // printf("\n Condition: %d %d", !feof(arq), (i < interval));
  } while(!feof(arq) && (i < interval+1 ));

  free(student);
}


void readAndShowSpecificRegistry(FILE *arq) {
  int specificRegistry = 0;
  scanf("%d", &specificRegistry);
  // int countOfElements = countOfElementsOnFile(arq);
  long sizeOfEachStruct = sumOfSizeOfStruct();

  long sizeOfStart = sizeOfEachStruct * (specificRegistry-1); // index
  STUDENT *specificStudent = (STUDENT *)malloc(sizeof(STUDENT));
  fseek(arq, sizeOfStart, SEEK_SET);

  fread(&specificStudent->nusp  , sizeof(int  )     , 1, arq);
  fread(&specificStudent->name  , sizeof(char ) * 50, 1, arq);
  fread(&specificStudent->course, sizeof(char ) * 50, 1, arq);
  fread(&specificStudent->grade , sizeof(float)     , 1, arq);
  printStudent(specificStudent);
  
  free(specificStudent);
}

int main () {
  char *filename = NULL;
  int operation = 0;

  filename = readLine();
  scanf("%d", &operation);
  
  FILE *file = fopen(filename, "rb+");

  if(file == NULL ) {
    printf("File not found or empty\n");
    return 0;
  }

  if(operation == 1) {
    readAndShowAllStudents(file);
  }
  if(operation == 2) {
    readAndShowStartToMiddleStudents(file);
  }
  if(operation == 3) {
    readAndShowMiddleToEndStudents(file);
  }
  if(operation == 4) {
    readAndShowTheIntervalOfStudents(file);
  }
  if(operation == 5) {
    readAndShowSpecificRegistry(file);
  }
}