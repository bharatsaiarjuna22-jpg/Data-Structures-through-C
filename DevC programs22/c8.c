#include <stdio.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

int isMatching(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

int isBalanced(char expr[]) {
    int i;
    for (i = 0; i < strlen(expr); i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            char popped = pop();
            if (!isMatching(popped, c))
                return 0;
        }
    }
}

int main() {
    char expr[MAX];
    printf("Enter an expression: ");
    scanf("%s", expr);

    if (isBalanced(expr)) {
        printf("Balanced parenthesis\n");
    } else {
        printf("Not Balanced\n");
    }
    return 0;
}

