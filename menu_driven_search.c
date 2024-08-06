#include<stdio.h>
void bubbleSort(int arr[], int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void linearSearch(int arr[], int n, int key)
{
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("Element found at index %d\n",i);
    }
    else
    {
        printf("Element not found\n");
    }
}
void inputArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}
void binarySearch(int arr[], int n, int key)
{
    int low=0,high=n-1,mid,flag=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==key)
        {
            flag=1;
            break;
        }
        else if(arr[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(flag==1)
    {
        printf("Element found at index %d\n",mid);
    }
    else
    {
        printf("Element not found\n");
    }
}
int main(){
    int n,choice,key;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    inputArray(arr,n);
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
    printf("1. Linear Search\n2. Binary Search\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: linearSearch(arr,n,key);
                break;
        case 2: bubbleSort(arr,n);
                binarySearch(arr,n,key);
                break;
        default: printf("Invalid choice\n");
    }
    return 0;
}