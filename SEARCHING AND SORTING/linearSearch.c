// Write a program  to serach an element in an array using the linear search technique

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define size 20

int main(){
    int arr[size], num, n, i, found = 0, pos = -1;
    
    // asking user to enter the number of elements 
    printf("\n Enter the number of elements in the array : ");
    scanf("%d",&n);

    // asking the user to enter the numbers
    printf("\n Enter the numbers : ");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // asking user to enter the number that has to be searched
    printf("\n Enter the number that has to be searched : ");
    scanf("%d",&num);

    // checking if that number is present in the array or not
    for(i = 0; i < n; i++){
        if(arr[i] == num){
            found = 1;
            pos = i;
            printf("\n %d  is found in the array at position %d ",num,i+1);
        }
    }

    if(found == 0)
    printf("\n %d does not exist in the array", num);
    return 0;
}