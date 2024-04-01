#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StudentData
{
    char name[50];
    int roll;
    int marks;
} student;

int main()
{
    int n = 3;

    FILE *filePTR;
    char *fileName = "studnetRawData.txt";
    filePTR = fopen(fileName, "w");
    student sem3[n];

    char *studentNames[] = {"Amit", "DDC", "Raghav"};
    int rolls[] = {12, 36, 50};
    int marks[] = {23, 96, 80};

    for (int i = 0; i < n; i++)
    {
        strcpy(sem3[i].name, studentNames[i]);
        sem3[i].marks = rolls[i];
        sem3[i].roll = marks[i];
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(filePTR,
                "%s, %d, %d\n",
                sem3[i].name,
                sem3[i].marks,
                sem3[i].roll);
    }
    fclose(filePTR);
    return 0;
}