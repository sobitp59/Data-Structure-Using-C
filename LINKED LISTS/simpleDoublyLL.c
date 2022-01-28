// SIMPLE DOUBLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};


// void printLinkedList(struct node *p){
//     while(p != NULL){
//         printf("%d->",p->data);
//         p = p->next;
//     }
// }

void printDoublyLinkedList(struct node *ptr){
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
}

int main(){

struct node *head;
struct node *one = NULL;
struct node *two = NULL;
struct node *three = NULL;
struct node *four = NULL;

one = malloc(sizeof(struct node));
two = malloc(sizeof(struct node));
three = malloc(sizeof(struct node));
four = malloc(sizeof(struct node));

one->data = 1;
two->data = 2; 
three->data = 3; 
four->data = 4;

one->prev = NULL;
one->next = two;

two->prev = one;
two->next = three;

three->prev = two;
three->next = four;

four->prev = three;
four->next = NULL;

head = one;

printDoublyLinkedList(head);
    return 0;
}

