#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void push(int str) {
    if ((rear == MAX - 1&&front==0) || (rear + 1 == front)) {
        printf("Queue is full\n");
    } else if (front == -1) {
            front = 0;
            rear = 0;
            queue[rear] = str;
        }
        else{
            rear = (rear + 1) % MAX;
        queue[rear] = str;
        }
        
    }

void pop() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Popped element is %d\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}