// LINKED QUEUEU
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *nextNodeAddress;
};
struct node *front;
struct node *rear;

void insert(){
    int num;
    printf("\n Enter the number to insert : ");
    scanf("%d",&num);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    ptr->nextNodeAddress = NULL;

    if(front == NULL && rear == NULL){
        front = rear = ptr;
        return;
    }else{
        rear->nextNodeAddress = ptr;
        rear = ptr;
    }
}

void dequeue(){
    struct node *ptr = front;
    if(front == NULL){
           printf("\n UNDERFLOW");
    }
    else if(front == rear){
        front = rear = NULL;
    }else{
        front = front->nextNodeAddress;
        printf("\n The number deleted is : %d",ptr->data);
    }
    free(ptr);
}

void peek(){
    struct node *ptr = front;
    if(front == NULL){
        printf("\n QUEUE IS EMPTY ");
    }else{
        return front->data;
    }
}

void display(){
    struct node *ptr = front;
    if(front == NULL)
        printf("\n QUEUE IS EMPTY");
    else{
        while(front != rear){
            printf("QUEUE : %d\t",front->data);
            front = front->nextNodeAddress;
        }

    }
}

int main(){
    int option;
    
}

int main(){


    return  0;
}