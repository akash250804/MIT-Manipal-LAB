#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->arr[++s->top] = c;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    }
    return '\0';
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void prefixToPostfix(char *prefix, char *postfix) {
    Stack s;
    initStack(&s);
    int postfixIdx = 0; // Index for postfix expression

    int length = strlen(prefix);
    for (int i = length - 1; i >= 0; i--) {
        char c = prefix[i];
        if (!isOperator(c)) {
            push(&s, c);
        } else {
            char operand1 = pop(&s);
            char operand2 = pop(&s);

            postfix[postfixIdx++] = operand1;
            postfix[postfixIdx++] = operand2;
            postfix[postfixIdx++] = c;
        }
    }
    postfix[postfixIdx] = '\0'; // Null terminate the postfix string
}

int main() {
    char prefix[MAX], postfix[MAX];
    printf("Enter prefix expression (without whitespaces): ");
    scanf("%s", prefix);

    prefixToPostfix(prefix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 17;
}
