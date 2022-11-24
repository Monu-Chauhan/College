#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
int front = -1, rear = -1, size = 0;
int queue[MAXSIZE];
void enqueue(int ele)
{
    if (size == MAXSIZE - 1)
    {
        printf("Queue is Full \n");
    }
    else if (rear == -1 || front == -1)
    {
        rear = rear + 1;
        front = front + 1;
        size = size + 1;
        queue[rear] = ele;
    }
    else
    {
        rear = rear + 1;
        queue[rear] = ele;
        size = size + 1;
    }
}
void display()
{
    if (front == -1)
    {
        printf("Empty queue\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}
void dequeue()
{
    if (front == -1)
    {
        printf("Underflow\n");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        size--;
    }
    else
    {
        int item;
        item = queue[front];
        front = front - 1;
        size--;
        printf("Deleted item = %d\n", item);
    }
}
void sizeOfQueue()
{
    printf("Size is %d\n", size);
}
void isEmpty()
{
    if (front == -1 || rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue is not empty\n");
    }
}
void isFull()
{
    if (size == MAXSIZE - 1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        printf("Not Full\n");
    }
}
void peek()
{
    printf("%d\n", queue[rear]);
}
int main()
{
    printf("1.enqueue 2.dequeue 3.size)fQueue 4.isEmpty 5.isFull 6.peek 7.display\n");
    printf("If you want to exit choose 8\n");
    int choice,ele;
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