// Circular Doubly Linked List
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    struct node *prevNode;
    int data;
    struct node *nextNode;
};

struct node *head = NULL;
struct node *createCircularDoublyLinkedList(struct node *);
struct node *displayCircularDoublyLinkedList(struct node *);
struct node *insertBeginning(struct node *);
struct node *insertEnd(struct node *);
struct node *deleteBeginning(struct node *);
struct node *deleteEnd(struct node *);
struct node *deleteNode(struct node *);
struct node *deleteList(struct node *);

int main()
{
    int option;
    do
    {
        printf("\n\n ********************** MAIN MENU *********************");
        printf("\n 1: Create a Circular Doubly Linked List ");
        printf("\n 2: Display the Circular Doubly Linked List ");
        printf("\n 3: Insert node at beginning of Circular Doubly Linked List ");
        printf("\n 4: Insert node at end of Circular Doubly Linked List ");
        printf("\n 5: Delete node at beginning of Circular Doubly Linked List ");
        printf("\n 6: Delete node at end of Circular Doubly Linked List ");
        printf("\n 7: Delete the node");
        printf("\n 8: Delete the list");
        printf("\n 9: EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            head = createCircularDoublyLinkedList(head);
            printf("\n Yay!! Circular Doubly Linked List Created");
            break;
        case 2:
            head = displayCircularDoublyLinkedList(head);
            break;
        case 3:
            head = insertBeginning(head);
            break;
        case 4:
            head = insertEnd(head);
            break;
        case 5: head = deleteBeginning(head);
            break;
        case 6: head = deleteEnd(head);
            break;
        case 7: head = deleteNode(head);
            break;
        case 8: head = deleteList(head);
            break;
        }
    } while (option != 9);

    return 0;
}

// Creating Circular Doubly Linked List
struct node *createCircularDoublyLinkedList(struct node *head)
{
    struct node *newNode, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);

    while (num != -1)
    {
        if (head == NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = num;
            // newNode->prevNode = NULL;
            // newNode->nextNode = head;
            // head = newNode;
            head = ptr = newNode;
            head->prevNode = head;
            head->nextNode = head;
        }
        else
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = num;
            ptr = head;
            while (ptr->nextNode != head)
                ptr = ptr->nextNode;
            ptr->nextNode = newNode;
            newNode->prevNode = ptr;
            newNode->nextNode = head;
            head->prevNode = newNode;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return head;
}

// Display Doubly Circular Linked List
struct node *displayCircularDoublyLinkedList(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr->nextNode != head)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->nextNode;
    }
    printf("%d\t", ptr->data);
    return head;
}

// Insert Node at Beginning Of the Node List
struct node *insertBeginning(struct node *head)
{
    struct node *newNode, *ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;

    ptr = head;
    while (ptr->nextNode != head)
      ptr = ptr->nextNode;
    newNode->prevNode = ptr;

    ptr->nextNode = newNode;
    newNode->nextNode = head;
    head->prevNode = newNode;
    head = newNode;
    return head;
}

// Insert Node at End of the Node List
struct node *insertEnd(struct node *head)
{
    struct node *newNode, *ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;

    ptr = head;
    while (ptr->nextNode != head)
        ptr = ptr->nextNode;
    ptr->nextNode = newNode;
    newNode->prevNode = ptr;
    newNode->nextNode = head;
    head->prevNode = newNode;
    return head;
}

// Delete node at beginning of Circular Doubly Linked List 
struct node *deleteBeginning(struct node *head){
    struct node *ptr, *temp;
    ptr = head;
    while(ptr->nextNode != head)
        ptr = ptr->nextNode;
    ptr->nextNode = head->nextNode;
    temp = head;
    head = head->nextNode;
    head->prevNode = ptr;
    free(temp);
    return head;
}

// Delete node at end of Circular Doubly Linked List
struct node *deleteEnd(struct node *head){
    struct node *ptr;
    ptr = head;
    while(ptr->nextNode != head)
        ptr = ptr->nextNode;
    ptr->prevNode->nextNode = head;
    head->prevNode = ptr->prevNode;
    free(ptr);
    return head;
}


// Delete the node 
struct node *deleteNode(struct node *head){
    struct node *ptr;
    int val;
    printf("\n Enter the value of the node which you want to delete : ");
    scanf("%d",&val);
    ptr = head;
   
   if(ptr->data == val){
       head = deleteBeginning(head);
       return head;
   }
   else{
       while(ptr->data != val)
         ptr = ptr->nextNode;
       ptr->prevNode->nextNode = ptr->nextNode;
       ptr->nextNode->prevNode = ptr->prevNode;
       free(ptr);
       return head; 
   }
}

//Delete the Entire List
struct node *deleteList(struct node *head){
    struct node *ptr;
    ptr = head;
    while(ptr->nextNode != head)
        head = deleteEnd(head);
        free(head);
        return head;
} 