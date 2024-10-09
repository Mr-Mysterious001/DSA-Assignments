#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int val;
    struct NODE *next;
};
struct NODE *start = NULL;
struct NODE *rear = NULL;
struct NODE *front = NULL;
void push(int val) {
    if (rear->next==front || (front==NULL && rear->next==NULL)) {
        printf("Queue is full\n");
    } else if(front==NULL){
        struct NODE *ptr=(struct NODE*)malloc(sizeof(struct NODE));
        ptr->val=val;
        ptr->next=NULL;
        start=ptr;
        front=ptr;
        rear=ptr;
    } else {
        struct NODE *ptr=(struct NODE*)malloc(sizeof(struct NODE));
        ptr->val=val;
        ptr->next=NULL;
        struct NODE *temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        rear=ptr;
    }
}
void pop(){
    if(front==NULL||front->next==NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("Poped element is %d\n",front->val);
        front->val=NULL;
        front=front->next;
    }
}
void display(){
    if(front==NULL){
        printf("Queue is empty\n");
    }
    else{
        struct NODE *temp=front;
        while(temp!=NULL)
        {
            printf("%d ",temp->val);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main(){
    int choice;
    int str;
    while(1){
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to push: ");
                scanf(" %d",&str);
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