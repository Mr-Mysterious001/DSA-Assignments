//Q.2 Write a program to delete a element from the middle of an array.
#include<stdio.h>
int main(){
    int A[20];
	int i,n,l=4;
	printf("Enter 5 nos.\n");
    for(i=0;i<=l;i++)
    scanf("%d",&A[i]);
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
