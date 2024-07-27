//Q.3 Write a menu program to insert, delete, input and display the array.
#include<stdio.h>
#include<stdlib.h>
int A[20],l=4;
void insert()
{
	int a,i,n;
    printf("Enter new number");
    scanf("%d",&a);
    printf("Enter index number");
    scanf("%d",&n);
    for(i=l+1;i>=0;i--)
    {
        if(i==n){
       	A[i]=a;
        break;
		}
        else
        A[i]=A[i-1];
    }
    l++;
    for(i=0;i<=l;i++)
    printf("%d",A[i]);
}
void delet()
{
	int i,n;
    printf("Enter index number");
    scanf("%d",&n);
    for(i=n;i<=l;i++)
    {
        A[i]=A[i+1];
    }
    A[l]=-1;
    l--;
    for(i=0;i<=l;i++)
    printf("%d",A[i]);
}
void input()
{
	int i;
	printf("Enter 5 nos.\n");
    for(i=0;i<=l;i++)
    scanf("%d",&A[i]);
}
void display()
{
	int i;
	for(i=0;i<=l;i++)
    printf("%d",A[i]);
}
int main()
{
	input();
	while(true){
		printf("Enter 1 to insert, 2 to delete and 3 to display array and 4 to quit");
		int ch;
		scanf("%d",ch);
		switch(ch){
			case 1:
				insert();
				break;
			case 2:
				delet();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Wrong Choice");
		}
	}
}
