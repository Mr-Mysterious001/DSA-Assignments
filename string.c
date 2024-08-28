#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

char stack[MAX];
int top = -1;

void push(char value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        char value = stack[top];
        top--;
        return value;
    }
}
int main()
{
    char str[MAX] = "";
    char str1[MAX] = "";
    printf("Enter a string: ");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++)
    {
        push(str[i]);
    }
    printf("Reversed string is: ");
    for (int i = 0; i < strlen(str); i++)
    {
        str1[i] = pop();
        printf("%c", str1[i]);
    }

    return 0;
}