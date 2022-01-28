// DOUBLY LINKED LIST IMPLETATION 
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

// structure of doubly linked list
struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *createDoublyLinkedList(struct node *);
struct node *displayDoublyLinkedList(struct node *);
struct node *insertBeginning(struct node *);
struct node *insertEnd(struct node *);
struct node *insertBefore(struct node *);
struct node *insertAfter(struct node *);
struct node *deleteBeginning(struct node *);
struct node *deleteEnd(struct node *);
struct node *deleteBefore(struct node *);
struct node *deleteAfter(struct node *);
struct node *deleteList(struct node *);

int main(){
  int option;
  do{
      printf("\n\n ************--> MAIN MENU <--*************");
      printf("\n 1: Create Doubly Linked List ");
      printf("\n 2: Display Doubly Linked List ");
      printf("\n 3: Insert Node At Beginnig");
      printf("\n 4: Insert Node At End");
      printf("\n 5: Insert Node Before A Given Node");
      printf("\n 6: Insert Node After A Given Node");
      printf("\n 7: Delete Node At Beginning");
      printf("\n 8: Delete Node At End");
      printf("\n 9: Delete A Node Before A Given Node");
      printf("\n 10: Delete A Node After A Given Node");
      printf("\n 11: Delete The Entire List");
      printf("\n 12: EXIT");
      printf("\n\n Enter Your Option : ");
      scanf("%d",&option);
      switch(option){
          case 1: head = createDoublyLinkedList(head);
          printf("\n YAY! DOUBLY LINKED LIST CREATED");
          break;
          case 2: head = displayDoublyLinkedList(head);
          break;
          case 3: head = insertBeginning(head);
          break;
          case 4: head = insertEnd(head);
          break;
          case 5: head = insertBefore(head);
          break;
          case 6: head = insertAfter(head);
          break;
          case 7: head = deleteBeginning(head);
          break;
          case 8: head = deleteEnd(head);
          break;
          case 9: head = deleteBefore(head);
          break;
          case 10: head = deleteAfter(head);
          break;
          case 11: head = deleteList(head);
          break;
      }
  }while(option!=12);

    return 0;
}

// Creating Doubly Linked List 
struct node *createDoublyLinkedList(struct node *head){
    struct node *newNode, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d",&num);
    while(num != -1){
        if(head == NULL){
            newNode = (struct node*)malloc(sizeof(struct node));
            newNode->prev = NULL;
            newNode->data = num;
            newNode->next = NULL;
            head = newNode;
        }else{
            ptr = head;
            newNode = (struct node*)malloc(sizeof(struct node));
            newNode->data = num;
            while(ptr->next != NULL){
                ptr = ptr->next;
                ptr->next = newNode;
                newNode->prev = ptr;
                newNode->next = NULL;
            }
            printf("\n Enter the data : ");
            scanf("%d",&num);
        }
        return head;
    }
}

// Display Doubly Linked List 
struct node *displayDoublyLinkedList(struct node *head){
    struct node *ptr;
    ptr = head;
    while(ptr->next != NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    return head;
}

// Insert Doubly Linked List At The Beginning
struct node *insertBeginning(struct node *head){
    struct node *newNode;
    int num;
    printf("\n Enter the data : ");
    scanf("%d",&num);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = num;
    head->prev = newNode;
    newNode->next = head;
    newNode->prev = NULL;
    head =  newNode;
    return head;
}


// Insert Doubly Linked List At End
struct node *insertEnd(struct node *head){
    struct node *newNode, *ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d",&num);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
        ptr->next = newNode;
        newNode->prev = ptr;
        newNode->next = NULL;
        return head;
    return head;
}

// Insert A Node Before A Given Node 
struct node *insertBefore(struct node *head){
    struct node *newNode, *ptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d",&num);
    printf("\n Enter the value of the node before which node has to be deleted : ");
    scanf("%d",&val);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = head;
    while(ptr->data != val)
        ptr = ptr->next;
        newNode->next = ptr;
        newNode->prev = ptr->prev;
        ptr->prev = newNode;
        return head;
}

// Insert A Node After A Given Node
struct node *insertAfter(struct node *head){
    struct node *newNode, *ptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d",&num);
    printf("\n Enter the value of the node after which the data has to be inserted : ");
    scanf("%d",&val);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = head;
    while(ptr->data != val)
        ptr = ptr->next;
        newNode->prev = ptr;
        newNode->next = ptr->next;
        ptr->next->prev = newNode;
        ptr->next = newNode; 
        return head;
}

// Delete A Node At Beginning
struct node *deleteBeginning(struct node *head){
    struct node *ptr;
    ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return head;
}

// Delete Node At End
struct node *deleteEnd(struct node *head){
    struct node *ptr;
    ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
        ptr->prev->next = NULL;
        free(ptr);
        return head;
}


// Delete A Node Before A Given Node 
struct node *deleteBefore(struct node *head){
    struct node *ptr ,*deletePtr;
    int val;
    printf("\n Enter the value of the node before which node has to be deleted : ");
    scanf("%d",val);
    ptr = head;
    while(ptr->data != val)
        ptr = ptr->next;
        deletePtr = ptr->prev;
        if(deletePtr == head){
            head = deleteBeginning(head);
        }else{
            ptr->prev = deletePtr->prev;
            deletePtr->prev->next = ptr;
        }
        free(deletePtr);
        return head;
}

// Delete A Node After A Given Node 
struct node *deleteAfter(struct node *head){
    struct node *ptr, *deletePtr;
    int val;
    printf("\n Enter the value of the node after which node has to be deleted : ");
    scanf("%d",&val);
    ptr = head;
    while(ptr->data != val)
        ptr = ptr->next;
        deletePtr = ptr->next;
        ptr->next = deletePtr->next;
        deletePtr->next->prev = ptr;
        free(deletePtr);
        return head;       
}

// Delete The Entire Node 
struct node *deleteList(struct node *head){
    while(head != NULL)
        head = deleteList(head);
        return head;
}