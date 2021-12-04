#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Student{
    int id;
    char Name[10];
};

struct Student arr[4];

void PrintStudent(struct Student s);
struct Student Fill(void);

void bubbleSort(void);

int main()
{
    int i;

    for(i=0;i<4;i++)
    {
        arr[i] = Fill();
    }

    bubbleSort();

    printf("\n---after sorting---\n");

    for(i=0;i<4;i++)
    {
        PrintStudent(arr[i]);
    }


    return 0;
}

void bubbleSort(void)
{
    int n=4;
    int i, j, swapped=1;
    struct Student temp;

    for(i=0;i<(n-1)&&swapped;i++)
    {
        swapped = 0;

        for(j=0;j<(n-1-i);j++)
        {
            if(strcmp(arr[j].Name,arr[j+1].Name)>0)
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                swapped = 1;
            }
        }
    }
}

void PrintStudent(struct Student s)
{
    int i;

    printf("\n");
    printf("The student ID is: %d\n", s.id);
    printf("The student name is: %s\n", s.Name);
}

struct Student Fill(void)
{
    struct Student s;
    int i;

    printf("Please, Enter the student ID: ");
    scanf("%d", &s.id);

    printf("Please, Enter the student Name: ");
    scanf("%s", s.Name);

    printf("\n");
    return s;
}
