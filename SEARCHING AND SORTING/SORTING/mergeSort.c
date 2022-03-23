// Write a program to implement merge sort

#include<stdio.h>
#include<stdlib.h>
#define size 100

void merge(int arr[], int, int, int);
void mergeSort(int arr[], int, int);

int main(){
    int arr[size], n;
    printf("\n enter the number of elements in the array : ");
    scanf("%d", &n);

    printf("\n enter the elements : ");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }


    mergeSort(arr,0,n-1);
    printf("\n the sorted array is : ");
    for(int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}

// program for merge function
// | 0 | 1 | 2 | 3 | 4 |   5  | 6 | 7 | 8 |
// | 4 | 5 | 3 | 7 | 8 |  1   | 9 | 2 | 6 |
// |beg|           |mid|mid+1|        |end|
// | i |           |mid| j |          |end|

void merge(int arr[], int beg, int mid, int end){
    int i=beg, j=mid+1, index=beg, temp[size], k;
   
    while((i <= mid) && (j <= end))
    {
        if(arr[i] < arr[j])
        {
            temp[index] = arr[i];
            i++;
        }
        else
        {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }

    if(i > mid)
    {
        while(j <= end)
        {
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i <= mid)
        {
            temp[index] = arr[i];
            i++;
            index++;
        }
    }

    for(k = beg; k < index; k++){
        arr[k] = temp[k];
    }
    
}

//program for merge sort function
void mergeSort(int arr[], int beg, int end){
    int mid;
    if(beg<end)
    {
        mid = (beg+end)/2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid+1, end);
        merge(arr,beg,mid,end);
    }
}