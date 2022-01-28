// SIMPLE SINGLY LINKED LIST
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *createLinkedList(struct node *);
struct node *displayLinkedList(struct node *);
struct node *insertBegining(struct node *);
struct node *insertEnd(struct node *);
struct node *insertBefore(struct node *);
struct node *insertAfter(struct node *);
struct node *deleteBeginning(struct node *);
struct node *deleteEnd(struct node *);
// struct node *deleteBefore(struct node *);
struct node *deleteAfter(struct node *);
struct node *deleteNode(struct node *);
struct node *deleteList(struct node *);
struct node *sortList(struct node *);

int main()
{
    int option;
    do
    {
        printf("\n\n ********* SINGLY LINKED LIST **********");
        printf("\n 1. Create Linked List");
        printf("\n 2. Display Linked List");
        printf("\n 3.Add Node at Begining");
        printf("\n 4.Add Node at End");
        printf("\n 5.Add node Before a given node");
        printf("\n 6.Add node After a given node");
        printf("\n 7.Delete a node from Beginning");
        printf("\n 8.Delete a node from END");
        // printf("\n 9.Delete a node BEFORE a given node");
        printf("\n 9.Delete a node AFTER a given node");
        printf("\n 10.Delete a given NODE");
        printf("\n 11.Delete the entire LIST");
        printf("\n 12. Sort the list");
        printf("\n 13. EXIT");
        printf("\n\n Enter Your Choice : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            head = createLinkedList(head);
            printf("Linked List Created");
            break;
        case 2:
            head = displayLinkedList(head);
            break;
        case 3:
            head = insertBegining(head);
            break;
        case 4:
            head = insertEnd(head);
            break;
        case 5:
            head = insertBefore(head);
            break;
        case 6:
            head = insertAfter(head);
            break;
        case 7:
            head = deleteBeginning(head);
            break;
        case 8:
            head = deleteEnd(head);
            break;
        // case 9: head = deleteBefore(head);
        // break;
        case 9:
            head = deleteAfter(head);
            break;
        case 10:
            head = deleteNode(head);
            break;
        case 11:
            head = deleteList(head);
            break;
        case 12:
            head = sortList(head);
            break;
        }
    } while (option != 13);
    return 0;
}

struct node *createLinkedList(struct node *head)
{
    struct node *newNode, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while (num != -1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;
        if (head == NULL)
        {
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newNode;
            newNode->next = NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return head;
}

struct node *displayLinkedList(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d \t", ptr->data);
        ptr = ptr->next;
    }
    return head;
}

struct node *insertBegining(struct node *head)
{
    struct node *newNode;
    int num;
    printf("\nEnter the data to insert at beginning : ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = head;
    head = newNode;
    return head;
}

struct node *insertEnd(struct node *head)
{
    struct node *newNode, *ptr;
    int num;
    printf("\nEnter the data to insert at the end : ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = NULL;
    ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newNode;
    return head;
}

struct node *insertBefore(struct node *head)
{
    struct node *newNode, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data to insert before a node : ");
    scanf("%d", &num);
    printf("\n Enter the value before which data has to be inserted : ");
    scanf("%d", &val);

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;

    ptr = head;
    while (ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newNode;
    newNode->next = ptr;
    return head;
}

struct node *insertAfter(struct node *head)
{
    struct node *newNode, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data to insert after a node : ");
    scanf("%d", &num);
    printf("\n Enter the value after which data has to be inserted : ");
    scanf("%d", &val);

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;

    ptr = head;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newNode;
    newNode->next = ptr;
    return head;
}

struct node *deleteBeginning(struct node *head)
{
    struct node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *deleteEnd(struct node *head)
{
    struct node *preptr, *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return head;
}

//------------------------------------------------------------------------- //
// struct node *deleteBefore(struct node *head){
//     struct node *ptr, *preptr, *preptrpre;
//     int val;
//     printf("\nEnter the value before which node has to be deleted : ");
//     scanf("%d",&val);
//     preptrpre = preptr;
//     preptr = ptr;
//     ptr = head;
//     while(ptr->data != val){
//         preptrpre = preptr;
//         preptr = ptr;
//         ptr = ptr->next;
//     }
//     preptrpre->next = ptr->next;
//     free(preptr);
//     return head;
//------------------------------------------------------------------------- //

// }

struct node *deleteAfter(struct node *head)
{
    struct node *ptr, *preptr;
    int val;
    printf("\nEnter the value after which node has to be deleted : ");
    scanf("%d", &val);
    ptr = head;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return head;
}

struct node *deleteNode(struct node *head)
{
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value of the  node which has to be deleted : ");
    scanf("%d", &val);
    ptr = head;
    if (ptr->data == val)
    {
        head = deleteBeginning(head);
        return head;
    }
    else
    {
        while (ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return head;
    }
}

struct node *deleteList(struct node *head)
{
    struct node *ptr;
    if (head != NULL)
    {
        ptr = head;
        while (ptr != NULL)
        {
            printf("\n %d is to be deleted next", ptr->data);
            head = deleteBeginning(ptr);
            ptr = head;
        }
    }
    return head;
}

struct node *sortList(struct node *head)
{
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = head;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return head;
}
