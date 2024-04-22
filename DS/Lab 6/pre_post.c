#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 100

typedef struct {
    char items[max];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == max - 1;
}

void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++s->top] = item;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

void prefixToPostfix(char prefix[]) {

    Stack s;
    initialize(&s);


    for (int i = 0; i < prefix[i] != '\0'; i++) {
        char sym = prefix[i];

        if (isalnum(sym))
        {
            printf("%c", sym);
        }
        else if (sym == ')' || sym == ']' || sym == '}')
        {
            push(&s, sym);
        }
        else if (sym == '(' || sym == '[' || sym == '{')
           {
            while (!isEmpty(&s) && s.items[s.top] != ')' && s.items[s.top] != ']' && s.items[s.top] != '}')
            {
                printf("%c", pop(&s));
            }
            if (!isEmpty(&s))
            {
                pop(&s);
            }
        }
        else
            {
            while (!isEmpty(&s) && s.items[s.top] != ')' && s.items[s.top] != '(' && s.items[s.top] >= sym)
{
                printf("%c", pop(&s));
            }
            push(&s, sym);
        }
    }

    while (!isEmpty(&s)) {
        printf("%c", pop(&s));
    }
}

int main() {
    char prefix[max];
    printf("Enter the prefix expression: ");
    scanf("%s", prefix);
    strrev(prefix);

    printf("Postfix expression: ");
    prefixToPostfix(prefix);
    printf("\n");

    return 0;
}

