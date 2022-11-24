#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
int queue[MAXSIZE];
int front=-1,rear=-1,size=0;
void enqueueAtrear(int ele)
{
    if((rear+1)%MAXSIZE==front)
    {
        printf("Overflow\n");
    }
    else if(rear==-1)
    {
        rear=0;
        front=0;
        size++;
        queue[rear]=ele;
    }
    else
    {
        rear=(rear+1)%MAXSIZE;
        queue[rear]=ele;
        size++;
    }
}
void dequeueAtrear()
{
    int item;
    if(rear==-1)
    {
        printf("Underflow\n");
    }
    else if(front== rear)
    {
        item = queue[rear];
        printf("Delete at rear %d\n",item);
        rear=front=-1;
        size=0;
    }
    else
    {
        item=queue[rear];
        printf("Delete at rear %d\n",item);
        size--;
        rear=(rear+MAXSIZE-1)%MAXSIZE;
    }
}
void enqueueAtfront(int ele)
{
    if((rear+1)%MAXSIZE==front)
    {
        printf("Full");
    }
    else if(front == -1)
    {
        front++;
        rear++;
        size++;
        queue[front]=ele;
    }
    else
    {
        front=(front+MAXSIZE-1)%MAXSIZE;
        queue[front]=ele;
        size++;
    }
}
void dequeueAtfront()
{
    int item;
    if(front==-1)
    {
        printf("Underflow\n");
    }
    else if (front == rear)
    {
        item = queue[front];
        printf("Delete at front %d\n",item);
        front=-1;
        rear=-1;
        size=0;
    }
    else
    {
        item=queue[front];
        printf("Delete at front %d\n",item);
        front=(front+1)%MAXSIZE;
        size--;
    }
    
}
void display()
{
    if(front==-1)
    {
        printf("Empty\n");
    }
    else
    {
        for(int i=front;i!=rear;i=(i+1)%MAXSIZE)
        {
            printf("%d\n",queue[i]);
        }
    }
}

int main()
{
    printf("1.enqueueAtrear 2.dequeueAtrear 3.size)fQueue 4.isEmpty 5.isFull 6.peek 7.display\n");
    printf("8.enqueueAtfront 9.dequeueAtfront\n");
    printf("If you want to exit choose 10\n");
    int choice, ele;
    while (1)
    {
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Enter value to insert : ");
            scanf("%d", &ele);
            enqueueAtrear(ele);
            break;
        case 2:
            dequeueAtrear();
            break;
       /* case 3:
            sizeOfQueue();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            isFull();
            break;
        case 6:
            peek();
            break;*/
        case 7:
            display();
            break;
        case 8:
            printf("Enter value to insert : ");
            scanf("%d", &ele);
            enqueueAtfront(ele);
            break;
        case 9:
            dequeueAtfront();
            break;
        case 10:
            exit(0);

        default:
            printf("Invalid input\n");
            break;
        }
    }
}