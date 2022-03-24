#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void readAndShowAllStudents(FILE *arq) {
  int size = countOfElementsOnFile(arq);
  struct student *students = (struct student *)malloc(sizeof(struct student) * size); // can be createStudentsStruct(size);
  fseek(arq, 0, SEEK_SET);
  int i;
  for (i = 0; i < size; i++) {
    fread(&students[i].nusp  , sizeof(int  )     , 1, arq);
    fread(&students[i].name  , sizeof(char ) * 50, 1, arq);
    fread(&students[i].course, sizeof(char ) * 50, 1, arq);
    fread(&students[i].grade , sizeof(float)     , 1, arq);
    printf("%d\n", students[i].nusp);
    printf("%s\n", students[i].name);
    printf("%s\n", students[i].course);
    printf("%.2f\n", students[i].grade);
  }
  free(students);
}

void readAndShowStartToMiddleStudents(FILE *arq) {
  int countOfElements = countOfElementsOnFile(arq)/2;
  struct student *students = (struct student *)malloc(sizeof(struct student) * countOfElements);
  int i;
  for (i = 0; i < countOfElements; i++) {
    fread(&students[i].nusp  , sizeof(int  )     , 1, arq);
    fread(&students[i].name  , sizeof(char ) * 50, 1, arq);
    fread(&students[i].course, sizeof(char ) * 50, 1, arq);
    fread(&students[i].grade , sizeof(float)     , 1, arq);
    printf("%d\n", students[i].nusp); // can be printStudent(students[i]);
    printf("%s\n", students[i].name);
    printf("%s\n", students[i].course);
    printf("%.2f\n", students[i].grade);
  }
  free(students);
}

void readAndShowMiddleToEndStudents(FILE *arq) {
  int countOfElements = countOfElementsOnFile(arq)/2;
  int fileSizeOfHalf = fsize(arq);
  struct student *students = (struct student *)malloc(sizeof(struct student) * countOfElements);
  int i;
  printf("Tamanho do arquivo: %d\n", fileSizeOfHalf);
  fseek(arq, fileSizeOfHalf/2, SEEK_SET);
  for (i = 0; i < countOfElements; i++) {
    fread(&students[i].nusp  , sizeof(int  )     , 1, arq);
    fread(&students[i].name  , sizeof(char ) * 50, 1, arq);
    fread(&students[i].course, sizeof(char ) * 50, 1, arq);
    fread(&students[i].grade , sizeof(float)     , 1, arq);
    printf("%d\n", students[i].nusp);
    printf("%s\n", students[i].name);
    printf("%s\n", students[i].course);
    printf("%.2f\n", students[i].grade);
  }
  free(students);
}

void readAndShowTheIntervalOfStudents(FILE *arq) {
  int start = 0;
  int end = 0;
  scanf("%d %d", &start, &end);
  printf("%d %d\n", start, end);
  int interval = end - start;

  // int countOfElements = countOfElementsOnFile(arq);
  long sizeOfEachStruct = sumOfSizeOfStruct();

  long sizeOfStart = sizeOfEachStruct * (start-1);
  fseek(arq, sizeOfStart, SEEK_SET);

  struct student *students = (struct student *)malloc(sizeof(struct student) * (interval));
  int i;
  int index = 0;

  for (i = 0; i < interval; i++) {
    index = i+start; // to access the right index
    printf("INDEX: %d\n", index);
    if(feof(arq)) {
      break;
    }
    fread(&students[index].nusp  , sizeof(int  )     , 1, arq);
    fread(&students[index].name  , sizeof(char ) * 50, 1, arq);
    fread(&students[index].course, sizeof(char ) * 50, 1, arq);
    fread(&students[index].grade , sizeof(float)     , 1, arq);
    printf("nUSP: %d\n", students[index].nusp);
    printf("Nome: %s\n", students[index].name);
    printf("Curso: %s\n", students[index].course);
    printf("Nota: %.2f\n", students[index].grade);

    if(feof(arq)) {
      break;
    }
    printf("\n");
  }
  free(students);
}


void readAndShowSpecificRegistry(FILE *arq) {
  int specificRegistry = 0;
  scanf("%d", &specificRegistry);
  // int countOfElements = countOfElementsOnFile(arq);
  long sizeOfEachStruct = sumOfSizeOfStruct();

  long sizeOfStart = sizeOfEachStruct * (specificRegistry-1); // index
  struct student *specificStudent = (struct student *)malloc(sizeof(struct student));
  fseek(arq, sizeOfStart, SEEK_SET);

  fread(&specificStudent->nusp  , sizeof(int  )     , 1, arq);
  fread(&specificStudent->name  , sizeof(char ) * 50, 1, arq);
  fread(&specificStudent->course, sizeof(char ) * 50, 1, arq);
  fread(&specificStudent->grade , sizeof(float)     , 1, arq);
  printf("%d\n",   specificStudent->nusp);
  printf("%s\n",   specificStudent->name);
  printf("%s\n",   specificStudent->course);
  printf("%.2f\n", specificStudent->grade);
  
  free(specificStudent);
}

int main () {
  char *filename = NULL;
  int operation = 0;

  filename = readLine();
  scanf("%d", &operation);
  
  printf("%s %d\n", filename, operation);
  FILE *file = fopen(filename, "r");

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