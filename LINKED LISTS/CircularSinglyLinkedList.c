// Circular Singly Linked List 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *createCircularLinkedList(struct node *);
struct node *displayCircularLinkedList(struct node *);
struct node *insertBeginning(struct node *);
struct node *insertEnd(struct node *);
struct node *deleteBeginning(struct node *);
struct node *deleteEnd(struct node *);
struct node *deleteAfter(struct node *);
struct node *deleteList(struct node *);

int main(){
    int option;
    do{
        printf("\n\n ************----> MAIN MENU <----*************");
        printf("\n 1: Create a Circular Linked List");
        printf("\n 2: Display the Circular Linked List");
        printf("\n 3: Insert node at the beginning");
        printf("\n 4: Insert node at the end");
        printf("\n 5: Delete node from the Beginning");
        printf("\n 6: Delete node at the end");
        printf("\n 7: Delete node after a given node");
        printf("\n 8: Delete the entire list");
        printf("\n 9: EXIT");
        printf("\n ENTER YOUR OPTION : ");
        scanf("%d",&option);
        switch(option){
            case 1: head = createCircularLinkedList(head);
            printf("\n YAY! CIRCULAR LINKED LIST CREATED ");
            break;
            case 2: head = displayCircularLinkedList(head);
            break;
            case 3: head = insertBeginning(head);
            break;
            case 4: head = insertEnd(head);
            break;
            case 5: head = deleteBeginning(head);
            break;
            case 6: head = deleteEnd(head);
            break;
            case 7: head = deleteAfter(head);
            break;
            case 8: head = deleteList(head);
            printf("\n Entire list deleted :(");
            break;
        }
    }while(option != 9);

    return 0;
}

// Create a circular linked list
struct node *createCircularLinkedList(struct node *head){
    struct node *newNode, *ptr;
    int num;
    printf("\n Enter -1 to END");
    printf("\n Enter the data : ");
    scanf("%d",&num);
    while(num != -1){
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = num;
        if(head == NULL){
            newNode->next = newNode;
            head = newNode;
        }else{
            ptr = head;
            while(ptr->next != head)
                ptr = ptr->next;
                ptr->next = newNode;
                newNode->next = head;
        }
        printf("\n Enter the data : ");
        scanf("%d",&num);
    }
    return head;
}

// Display the Circular Linked List 
struct node *displayCircularLinkedList(struct node *head){
    struct node *ptr;
    ptr = head;
    while(ptr->next != head){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
        printf("%d\t",ptr->data);
        return head;
}

// Insert Node at Beginning
struct node *insertBeginning(struct node *head){
    struct node *newNode, *ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d",&num);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = head;
    while(ptr->next != head)
        ptr = ptr->next;
        ptr->next = newNode;
        newNode->next = head;
        head = newNode;
        return head;
}

// Insert Node at End
struct node *insertEnd(struct node *head){
    struct node *newNode, *ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d",&num);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = head;
    while(ptr->next != head)
        ptr = ptr->next;
        ptr->next = newNode;
        newNode->next = head;
        return head;
 }

// Delete node from the beginning
 struct node *deleteBeginning(struct node *head){
    struct node *ptr;
    ptr = head;
    while(ptr->next != head)
        ptr = ptr->next;
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        return head;
}

// Delete Node At The End
struct node *deleteEnd(struct  node *head){
     struct node *ptr, *prePtr;
    ptr = head;
    while(ptr->next != head){
    prePtr = ptr;
    ptr = ptr->next;
    }
    prePtr->next = ptr->next;
    free(ptr);
    return head;
}   

// Delete Node after  a given node
struct node *deleteAfter(struct  node *head){
    struct node *ptr, *prePtr;
    int val;
    printf("\n Enter the value of the node after which node has to be deleted : ");
    scanf("%d",&val);
    ptr = head;
    while(ptr->data != val){
        prePtr = ptr;
        ptr = ptr->next;
    }
    prePtr->next = ptr->next;
    if(ptr == head)
        head = prePtr->next;
        free(ptr);
        return head;
}

// Delete the entire List

struct node *deleteList(struct node *head){
    struct node *ptr;
    ptr = head;
    while(ptr->next != head)
        head = deleteEnd(head);
        free(head);
        return head;
}