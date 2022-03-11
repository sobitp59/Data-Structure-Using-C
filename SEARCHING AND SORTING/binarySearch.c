// write a program  to seacrch an element in an array using binary search
// Prerequisite : array must be sorted


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 10

int smallest(int arr[], int k, int n);
void selectionSort(int arr[], int n); 

int main(){
    int arr[size], n, num, i, beginningElement=0, endElement=n-1, midElement, found=0; 
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);

    printf("\n Enter the elements : ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // sorting the array the user gave
    selectionSort(arr, n);
    printf("\n The sorted array  is : ");
    for(i=0; i<n; i++){
        printf("%d \t",arr[i]);
    }

    // asking user the number  to be searched
    printf("\n\n Enter the number to be searched : ");
    scanf("%d", &num);

    while (beginningElement < endElement)
    {
        midElement = (beginningElement + endElement) / 2;
        if(arr[midElement] == num){
            printf("\n %d is found in the array at position %d", num, midElement+1);
            found = 1;
            break;
        }
        else if(arr[midElement] > num)
        endElement = midElement -1;
        else
        beginningElement = midElement +1;

    }
    if(beginningElement > endElement && found == 0)
    printf("\n %d is not found in the array",num);
    return 0;
}

// finding the smallest number 
int smallest(int arr[], int k, int n){  // 'k' is the beginnig element of the array
    int pos = k, smallestNum = arr[k], i;
    for(i = k+1; i < n; i++){
        if(arr[i] < smallestNum)
        {
            smallestNum = arr[i];
            pos = i;
        }
    }
    return pos;
}

// sorting the list
void selectionSort(int arr[], int n){
    int k, pos, temp;
    for(k = 0; k < n; k++){
        pos = smallest(arr, k, n);
        temp = arr[k];
        arr[k] = arr[pos];
        arr[pos] = arr[k];
    }
}