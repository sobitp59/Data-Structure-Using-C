// write a program to sort an array using selection sort algorithm

#include<stdio.h>
#include<stdlib.h>

void selectionSort(int arr[], int n);

int main(){
    int arr[10], n;
    printf("\n enter the number of elements in the array : ");
    scanf("%d", &n);

    printf("\n enter the elements in the array : ");
    for(int i = 0; i < n; i++)  scanf("%d",&arr[i]);
    
    
    printf("\n the sorted array is : ");
    selectionSort(arr, n);
    for(int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    } 
    return 0;
}

int smallestElementPosition(int arr[],int n, int k){
    int positionOfSmallestElement = k, smallestElement = arr[k];
    for(int i = k+1; i < n; i++){
        if(arr[i] < smallestElement){
            smallestElement = arr[i];
            positionOfSmallestElement = i;
        }
    }
    return positionOfSmallestElement;
}


void selectionSort(int arr[], int n){
    int positionOfElement, temp;
    for(int i = 0; i < n; i++){
        positionOfElement = smallestElementPosition(arr, n, i);
        temp = arr[i];
        arr[i] = arr[positionOfElement];
        arr[positionOfElement] = temp;
    }
}