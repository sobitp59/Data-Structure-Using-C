// Write a program to enter n numbers in an array. Redisplay the array with elements being sorted in ascending order

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, arr[10], i, j, temp, flag = 0;

    printf("\n Enter the number of elements in the array : ");
    scanf("%d",&n);

    printf("\n Enter the elements : ");
    for(i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
           if(arr[j] > arr[j+1])
           {
               temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
               flag = 1;
           }
        }
        if(flag == 0) break;
    }

    printf("\n The array sorted in ascending order is : ");
    for(i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}

// optimized bubble sort : best for sorted array
// Complexity ::
// Bubble Sort : o(n(sqaure))
// Optimized Bubble Sort : O(n)