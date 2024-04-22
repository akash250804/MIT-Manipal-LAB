#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 100

struct stack{
    int arr[max];
    int top;
};

struct stack s;

void initialize(struct stack* s){
    s->top=-1;
}

void push(struct stack *s, char value) {
    if (s->top == max - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = value;
}


char pop(struct stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    char value = s->arr[s->top];
    s->top--;
    return value;
}

bool areParenthesesMatching(const char * exp) {
    struct stack s;
    initialize(&s);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(&s, exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            char popped = pop(&s);
            if ((exp[i] == ')' && popped != '(') ||
                (exp[i] == '}' && popped != '{') ||
                (exp[i] == ']' && popped != '[')) {
                return false; // for Unbalanced...
            }
        }
    }

    return s.top == -1; // for Balanced...
}


int main() {
    char expression[max];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (areParenthesesMatching(expression)) {
        printf("Parentheses are Balanced.\n");
    } else {
        printf("Parentheses are not Balanced.\n");
    }

    return 0;
}
