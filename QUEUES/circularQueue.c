#include <stdio.h>

#define MAX 10
int queue[MAX];
int front = -1, rear = -1;

void insert(void);
int delete (void);
int peek(void);
void display(void);

int main()
{
    int option, val;
    do
    {
        printf("\n ****** MAIN MENU ******");
        printf("\n 1.INSERT");
        printf("\n 2.DELETE");
        printf("\n 3.DISPLAY");
        printf("\n 4.PEEK");
        printf("\n 5.EXIT");
        printf("\n Enter your option to perform Circular Queue Operation : ");
        scanf("%d", &option);

        switch (option)
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
            display();
            break;
        case 4:
            val = peek();
            if (val != -1)
                printf("\n The number at first is : %d", val);
            break;
        }
    } while (option != 5);

    return 0;
}

// INSERTION

void insert()
{
    int num;
    printf("\nEnter the number to insert : ");
    scanf("%d", &num);
    if (front == 0 && rear == MAX - 1)
        printf("\n OVERFLOW!!");
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = num;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = num;
    }
    else
    {
        rear++;
        queue[rear] = num;
    }
}

// DELETION
int delete()
{
    int val;
    if (front == -1 && rear == -1)
    {
        printf("\n UNDERFLOW!!");
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
        printf("\n QUEUE IS EMPTY");
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
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\n QUEUE IS EMPTY ");
    }
    else
    {
        printf("\n QUEUE is : ");
         while (i != rear)
        {
            printf("%d\t",queue[i]);
            i = (i + 1) % MAX;
        }
    }
        printf("%d",queue[rear]);
}