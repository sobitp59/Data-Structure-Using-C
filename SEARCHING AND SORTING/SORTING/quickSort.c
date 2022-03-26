// write a program to implement quick sort algorithm

#include<stdio.h>
#include<stdlib.h>
#define size 100

int partition(int a[], int beg, int end);
void quickSort(int a[], int beg, int end);
int swap(int a[], int b[]);

int main(){
    int arr[size], n;
    printf("\n enter the number of elements in the array : ");
    scanf("%d",&n);

    printf("\n enter the elements in the array : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n-1);
    printf("\n the sorted (quick sort) array is :  ");
    for(int i = 0; i < n; i++){
        printf("%d \t",arr[i]);
    }

    return 0;
}

//  4 | 5 | 6 | 3 | 2 | 7 | 9
// program for partition
int partition(int a[], int beg, int end){
    int temp;
    int pivot = a[end];
    int partitionIndex = beg;
    for(int i = beg; i < end; i++)
    {
        if(a[i]<= pivot){
            temp = a[i];
            a[i] = a[partitionIndex];
            a[partitionIndex] = temp;
            partitionIndex++;
        }
    }
    temp = a[partitionIndex];
    a[partitionIndex] = a[end];
    a[end] = temp;

    return partitionIndex;
}


// program for quick sort 
void quickSort(int a[], int beg, int end){
    int partitionIndex;
    if(beg < end)
    {
        partitionIndex = partition(a,beg,end);
        quickSort(a, beg, partitionIndex-1);
        quickSort(a, partitionIndex+1, end);
    }
}

