#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 10
int queue[MAXSIZE];
int front = -1,rear = -1,size=0;
void enqueue(int ele)
{
    if((rear+1)%MAXSIZE==front)
    {
        printf("Overflow\n");
    }
    else if (rear == -1)
    {
        rear++;
        front++;
        size++;
        queue[rear]= ele;
    }
    else
    {
        rear=(rear+1)%MAXSIZE;
        queue[rear]=ele;
        size++;
    }
    
}
void dequeue()
{
    if(front==-1)
    {
        printf("Underflow\n");
    }
    else if(rear==front)
    {
        rear=-1;
        front=-1;
        size=0;
    }
    else
    {
        front=(front+1)%MAXSIZE;
        size--;
    }
}
int peek()
{
    return queue[rear];
}
int sizeOfQueue()
{
    return size;
}
bool isEmpty()
{
    return front == -1;
}
bool isFull()
{
    return size==MAXSIZE-1;
}
void display()
{
    if(isEmpty())
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
    printf("1.enqueue 2.dequeue 3.size)fQueue 4.isEmpty 5.isFull 6.peek 7.display\n");
    printf("If you want to exit choose 8\n");
    int choice,ele,value;
    while (1)
    {
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            
            printf("Enter value to insert : ");
            scanf("%d", &ele);
            enqueue(ele);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            value=sizeOfQueue();
            printf("Size is %d\n",value);
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            isFull();
            break;
        case 6:
            peek();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);

        default:
            printf("Invalid input\n");
            break;
        }
    }
}