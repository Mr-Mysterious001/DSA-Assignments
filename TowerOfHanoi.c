#include<stdio.h>
void toh(int  n, char beg, char end, char aux)
{
    if(n==1)
    {
        printf("Move disk %d from %c to %c\n",n,beg,end);
    }
    else{
        toh(n-1,beg,aux,end);
        printf("Move disc %d from %c to %c\n",n,beg,end);
        toh(n-1, aux,end,beg);
    }
}
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    toh(n,'A','C','B');
    return 0;
    
}