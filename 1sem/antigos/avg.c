#include <stdio.h>

int main()
{
    float lowGrade=0, highGrade=0, grade = 0, lowGradeStudent=0, highGradeStudent=0;
    do {
        scanf("%f", &grade);
        if(grade < 0 ) break;
        if (grade >= 5.0){
            highGrade += grade;
            highGradeStudent++;
        } 
        if(grade >= 0 && grade < 5.0)  {
            lowGrade += grade;
            lowGradeStudent++;
        }
        fflush(stdin);
    }while(grade >= 0);
    printf("%.0f %.0f %.0f %.0f", highGradeStudent, lowGradeStudent, (lowGrade + highGrade)/(lowGradeStudent+highGradeStudent), (highGradeStudent/(highGradeStudent+lowGradeStudent)) *100 );
    return 0;
}
