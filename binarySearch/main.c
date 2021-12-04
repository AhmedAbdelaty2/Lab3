#include <stdio.h>
#include <stdlib.h>

struct Student{
    int id;
    char Name[10];
};

void PrintStudent(struct Student s);
struct Student Fill(void);

int binarySearch(struct Student arr[], int lb, int ub, int data);


int main()
{
    struct Student s[6];
    int loc, i, id;

    for(i=0;i<6;i++)
    {
        s[i] = Fill();
    }

    printf("enter the student id that you want to search: ");
    scanf("%d",&id);

    loc = binarySearch(s,0,6,id);

    if(loc == -1)
        printf("\nthere is no student with this id\n");
    else
        printf("\nthe location of the student is %d\n", loc);



    return 0;
}

int binarySearch(struct Student arr[], int lb, int ub, int data)
{
    int mid;
    int loc = -1;

    while(lb<=ub && loc==-1)
    {
        mid = (lb+ub)/2;

        if(arr[mid].id == data)
            loc = mid;

        else if(arr[mid].id<data)
            lb = mid+1;

        else
            ub = mid-1;
    }

    return loc;
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
