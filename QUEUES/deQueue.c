// DATA STRUCTURE AND ALGORITHM : DEQUEUE IN C
#include <stdio.h>
#include <conio.h>
#define MAX 10

int deque[MAX];
int left = -1, right = -1;

void inputDeque(void);
void outputDeque(void);

void insertLeft(void);
void insertRight(void);
void deletetLeft(void);
void deleteRight(void);

void display(void);

int main()
{
    int option;
    printf("\n ********** MAIN MENU **********");
    printf("\n 1. INPUT RESTRICTED DEQUE");
    printf("\n 2. OUTPUT RESTRICTED DEQUE");
    printf("\n Enter Your Option : ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        inputDeque();
        break;
    case 2:
        outputDeque();
        break;
    }
    return 0;
}

// INPUT RESTRICTED DEQUE
void inputDeque()
{
    int choice;
    do
    {
        printf("\n **** THIS IS INPUT RESTRICTED DEQUE ****");
        printf("\n 1. -> Insert at RIGHT");
        printf("\n 2. -> Delete from LEFT ");
        printf("\n 3. -> Delete from RIGHT ");
        printf("\n 4. -> Display");
        printf("\n 5. -> EXIT");
        printf("\n Enter your option : ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertRight();
            break;
        case 2:
            deletetLeft();
            break;
        case 3:
            deleteRight();
            break;
        case 4:
            display();
            break;
        }
    } while (choice != 5);
}

// OUTPUT RESTRICTED DEQUE
void outputDeque()
{
    int choice;
    do
    {
        printf("\n **** THIS IS OUTPUT RESTRICTED DEQUE ****");
        printf("\n 1. -> Insert at RIGHT");
        printf("\n 2. -> Insert at LEFT ");
        printf("\n 3. -> Delete from LEFT ");
        printf("\n 4. -> Display");
        printf("\n 5. -> EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertRight();
            break;
        case 2:
            insertLeft();
            break;
        case 3:
            deleteLeft();
            break;
        case 4:
            display();
            break;
        }
    } while (choice != 5);
}

// INSERT RIGHT
void insertRight()
{
    int num;
    printf("\n Enter the number to be inserted(atRIGHT) : ");
    scanf("%d", &num);
    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf("\n OVERFLOWED!!! OH NO!!");
    }
    else if (left == -1)
    {
        left = 0;
        right = 0;
    }
    else
    {
        if (right == MAX - 1)
        {
            right = (right + 1) % MAX;
        }
        else
        {
            right = right + 1;
        }
    }
    deque[right] = num;
}

// INSERT LEFT
void insertLeft()
{
    int val;
    printf("\n Enter the number to be inserted(atLEFT) : ");
    scanf("%d", &val);
    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf("\n OVERFLOWED!!! OH NO!!");
    }
    else if (left == -1)
    {
        left = 0;
        right = 0;
    }
    else
    {
        if (left == 0)
        {
            left = MAX - 1;
        }
        else
        {
            left = left - 1;
        }
    }
    deque[left] = val;
}

// DELETE LEFT
void deleteLeft()
{
    if (left == -1)
    {
        printf("\n UNDERFLOWWW!! HOW CAN I DELETE?");
    }
    printf("\n The deleted element is : %d ", deque[left]);
    if (left == right)
    {
        left == -1;
        right == -1;
    }
    else
    {
        if (left == MAX - 1)
        {
            left = 0;
        }
        else
        {
            left = left + 1;
        }
    }
}

// DELETE RIGHT
void deleteRight()
{
    if (left == -1)
    {
        printf("\n UNDERFLOWWW!! I AM NOT ABLE TO DELETE! :(");
    }
    printf("\n The element deleted is : %d", deque[right]);
    if (left == right)
    {
        left == -1;
        right == -1;
    }
    else
    {
        if (right == 0)
        {
            right = MAX - 1;
        }
        else
        {
            right = right - 1;
        }
    }
}

// DISPLAY
void display()
{
    
}