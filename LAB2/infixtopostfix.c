#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

char stack[MAX];
int top = -1;

void push(char);
char pop();
int precedence(char);
void infixToPostfix(char infix[], char postfix[]);

void push(char item) {
    if (top == MAX - 1) {
        printf("Overflow!\n");
    } else {
        top++;
        stack[top] = item;
    }
}

char pop() {
    if (top == -1) {
        printf("Underflow!\n");
    } else {
        char popped = stack[top];
        top--;
        return popped;
    }
}

int precedence(char symbol) {
    if (symbol == '^') {
        return 3;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    } else {
        return -1;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char symbol, temp;

    push('#');

    while ((symbol = infix[i++]) != '\0') {
        if (symbol == '(') {
            push(symbol);
        } else if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } else if (symbol == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            temp = pop(); // Remove '(' from the stack
        } else {
            while (precedence(stack[top]) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

    while (stack[top] != '#') {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("The postfix exp is: %s\n", postfix);
    return 0;
}