#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 5
char queue[MAX];
front=-1;
rear=-1;
void push(char str) {
    if (rear == MAX - 1) {
        printf("Stack is full\n");
    } else {
        rear++;
        queue[rear] = str;
    }
}
void pop(){
    if(front>rear || front==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("Poped element is %c\n",queue[front]);
        front++;
    }
}
void display(){
    if(front>rear || front==-1){
        printf("Queue is empty\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%c ",queue[i]);
        }
        printf("\n");
    }
}
int main(){
    int choice;
    char str;
    while(1){
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to push: ");
                scanf(" %c",&str);
                push(str);
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
