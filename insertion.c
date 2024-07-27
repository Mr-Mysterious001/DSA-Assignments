//Q.1 Write a program to insert an element in the array at a given index.
#include<stdio.h>
int main(){
    int A[20];
	int a,i,n,l=4;
    for(i=0;i<=l;i++)
    scanf("%d",&A[i]);
    printf("Enter new number");
    scanf("%d",&a);
    printf("Enter index number");
    for(i=l+1;i<=0;i++)
    {
        if(i==n)
        A[i]=a;
        else
        A[i]=A[i-1];
    }
    l++;
}
