// Write a program to sort an array using insertion sort algorithm

#include <stdio.h>
#include <stdlib.h>
#define size 5

void insertionSort(int arr[], int n);

int main()
{
    int arr[size], i, n;
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\n Enter the elements of the array : ");
    for(i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    insertionSort(arr, n);

    printf("\n The sorted array is : ");
    for(i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }

    return 0;
}

void insertionSort(int arr[], int n){
    int i, j, temp;
    for(i = 1; i < n; i++){
        temp = arr[i];
        j = i-1;
        while((j >= 0) && (temp < arr[j])){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
