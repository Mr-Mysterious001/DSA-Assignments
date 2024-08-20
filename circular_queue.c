#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void push(int num)
{
    if ((front == 0 && rear == MAX - 1) || front == rear + 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == MAX - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        queue[rear] = num;
    }
}

    void pop()
    {
        if (front == -1)
        {
            printf("Queue is empty\n");
        }
        else
        {
            printf("Popped element is %d\n", queue[front]);
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else if (front == MAX - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
        }
    }

    void display()
    {
        if (front == -1)
        {
            printf("Queue is empty\n");
        }
        else
        {
            int i = front;
            while (1)
            {
                printf("%d ", queue[i]);
                if (i == rear)
                {
                    break;
                }
                if (i == MAX - 1)
                {
                    i = 0;
                }
                else
                {
                    i++;
                }
            }
            printf("\n");
        }
    }

    int main()
    {
        int choice;
        int num;
        while (1)
        {
            printf("1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &num);
                push(num);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
            }
        }
        return 0;
    }