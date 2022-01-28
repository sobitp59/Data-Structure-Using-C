// SIMPLE SINGLY LINKED LIST EXAMPLE

#include <stdio.h>
#include <stdlib.h>

// Creating A Node
struct node
{
    int data;
    struct node *next;
};

void printLinkedList(struct node *p){
    while(p != NULL){
        printf("%d->",p->data);
        p = p->next;
    }
}

int main(){
    // Initialize Node
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;
    struct node *four = NULL;

    // Allocate Memory
    one = (struct node *)malloc(sizeof(struct node));
    two = (struct node *)malloc(sizeof(struct node));
    three = (struct node *)malloc(sizeof(struct node));
    four = (struct node *)malloc(sizeof(struct node));

    // Assign Value
    one->data = 1;
    two->data = 2;
    three->data = 3;
    four->data = 4;

    // Connecting Nodes
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;

    // Printing Node 
    head = one;
    printLinkedList(head);
}

