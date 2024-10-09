#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int val;
    struct NODE *next;
};
struct NODE *start = NULL;
void insert(int val)
{
    struct NODE *ptr=(struct NODE*)malloc(sizeof(struct NODE));
    ptr->val=val;
    ptr->next=NULL;
    if(start==NULL)
    {
        start=ptr;
    }
    else
    {
        struct NODE *temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
    }
}
void display()
{
    struct NODE *temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->val);
        temp=temp->next;
    }
}
void count()
{
    struct NODE *temp=start;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("Number of elements in the linked list is %d",count);
}
int main()
{
    while(1)
    {
        int ch;
        printf("\n1. Insert\n2. Display\n3. Count\n4. Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                int val;
                printf("Enter the value to be inserted: ");
                scanf("%d",&val);
                insert(val);
                break;
            case 2:
                display();
                break;
            case 3:
                count();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
}