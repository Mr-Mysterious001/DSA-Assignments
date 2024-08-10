#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char str) {
    if (top == MAX - 1) {
        printf("Stack is full\n");
    } else {
        top++;
        stack[top] = str;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        char str = stack[top];
        top--;
        return str;
    }
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from stack
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char* postfix) {
    int i = 0;
    int stack[MAX];
    int top = -1;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            stack[++top] = postfix[i] - '0';
        } else {
            int val1 = stack[top--];
            int val2 = stack[top--];
            switch (postfix[i]) {
                case '+': stack[++top] = val2 + val1; break;
                case '-': stack[++top] = val2 - val1; break;
                case '*': stack[++top] = val2 * val1; break;
                case '/': stack[++top] = val2 / val1; break;
            }
        }
        i++;
    }
    return stack[top];
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of evaluation: %d\n", result);

    return 0;
}