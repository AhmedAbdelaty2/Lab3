#include <stdio.h>
#include <stdlib.h>

struct Student{
    int id;
    char Name[10];
};

struct Student arr[4];

void PrintStudent(struct Student s);
struct Student Fill(void);

void mergeSort(int low, int high);
void merge(int low, int mid, int high);

int main()
{
    int i;

    for(i=0;i<4;i++)
    {
        arr[i] = Fill();
    }

    mergeSort(0,3);

    printf("\n---after sorting---\n");

    for(i=0;i<4;i++)
    {
        PrintStudent(arr[i]);
    }

    return 0;
}

void mergeSort(int low, int high)
{
    int mid;

    if(low<high)
    {
        mid = (low+high)/2;
        mergeSort(low,mid);
        mergeSort(mid+1,high);
        merge(low,mid,high);
    }
}

void merge(int low, int mid, int high)
{
    struct Student temp[4];
    int list1,list2,i;

    list1 = low;
    i = low;
    list2 = mid+1;

    while(list1<=mid && list2<=high)
    {

        if(arr[list1].id<arr[list2].id)
        {
            temp[i] = arr[list1];
            list1++;
            i++;
        }

        else
        {
            temp[i] = arr[list2];
            list2++;
            i++;
        }
    }

    while(list1<=mid)
    {
        temp[i] = arr[list1];
        list1++;
        i++;
    }

    while(list2<=high)
    {
        temp[i] = arr[list2];
        list2++;
        i++;
    }

    for(i=low;i<=high;i++)
        arr[i] = temp[i];
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
