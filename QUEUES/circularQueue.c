#include <stdio.h>
#include <conio.h>

#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;

void insert(void);
int delete (void);
int peek(void);
void display(void);

int main()
{
    int choice, val;
    do
    {
        printf("\n ****** MAIN MENU ******");
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Peek");
        printf("\n4.Display");
        printf("\n5.Exit");
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            val = delete();
            if (val != -1)
                printf("\n The number deleted is : %d", val);
            break;
        case 3:
            val = peek();
            if (val != -1)
                printf("\n The number at first is : %d", val);
            break;
        case 4:
            display();
            break;
        }
    } while (choice != 5);

    return 0;
}

// INSERTION
void insert()
{
    int num;
    printf("\n Enter the number to insert : ");
    scanf("%d", &num);
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("\n QUEUE OVERFLOWED!!!");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = num;
    }
}

// DELETION
int delete()
{
    int val;
    if (front == -1 && rear == -1)
    {
        printf("\n QUEUE IS EMPTY!!!");
    }
    else
    {
        val = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
        return val;
    }
}

// PEEK
int peek()
{
    int val;
    if (front == -1 && rear == -1)
    {
        printf("\n QUEUE IS EMPTY!!!");
    }
    else
    {
        val = queue[front];
        return val;
    }
}

// DISPLAY
void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("\n QUEUE IS EMPTY!! OH NO!!");
    }
    else
    {
        printf("\n FRONT -> %d", front);
        printf("\n QUEUE IS : ");
        for (i = front; i != rear; i = (i + 1) % MAX)
        {
            printf("\t%d", queue[i]);
        }
        printf("\t%d", queue[i]);

        printf("\n REAR -> %d", rear);
    }
}