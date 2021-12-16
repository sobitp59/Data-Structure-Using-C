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
    int options, val;
    do
    {
        printf("\n ****** MAIN MENU ******");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &options);

        switch (options)
        {
        case 1:
            insert();
            break;
        case 2:
            val = delete ();
            if (val != -1)
                printf("\n The number deleted is : %d ", val);
            break;
        case 3:
            val = peek();
            if (val != -1)
                printf("\n The number at first is : %d", val);
            break;
        case 4:
            display();
        }
    } while (options != 5);
    getch();
    return 0;
}

void insert(){
    int num;
    printf("\n Enter the number to insert : ");
    scanf("%d",&num);
    if(rear == MAX-1)
    printf("\n QUEUE IS FULL ");
    else if(front == -1 && rear == -1)
    front = rear = 0;
    else
    rear++;
    queue[rear] = num;
}

int delete(){
    int val;
    if(front == -1 || rear  == -1)
    {
        printf("\n QUEUE IS EMPTY");
    }else{
        val = queue[front];
        front++;
        if(front > rear)
        front = rear = -1;
        return val;
    }
}

int peek(){
    int val;
    if(front == -1 && front > rear)
    {
        printf("\n QUEUE IS EMPTY ");
    }else{
        val = queue[front];
        return val;
    }
}

void display(){
    int i;
    printf("\n");
    if(front == -1 || front > rear)
    printf("'\n QUUEUE IS EMPTY");
    else{
        for ( i = front; i <= rear; i++)
        {
            printf("\t %d",queue[i]);
        }
        
    }
}