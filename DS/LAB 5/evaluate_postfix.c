#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define max 100

struct stack
{
    char a[max];
    int top;
};

typedef struct stack s;

void initialize(struct stack *s)
{
    s->top = -1;
}

void push(struct stack *s,int val)
{
    if(s->top == max-1)
        printf("Stack OverFlow...");
        else{
            s->a[++s->top]=val;
        }
}

char pop(struct stack *s)
{
    if(s->top == -1)
        printf("Stack UnderFlow...");
    else{
            return s->a[s->top--];
    }
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int evaluate(char *postfix)
{
    struct stack s;
    initialize(&s);

    for(int i=0;postfix[i] != '\0'; i++)
        {
        if(isdigit(postfix[i]))
        {
            push(&s,postfix[i] - '0');
        }
        else if(isOperator(postfix[i]))
        {
            int oper2 = pop(&s);
            int oper1 = pop(&s);
            int result;

            switch (postfix[i])
            {
                case '+': result = oper1 + oper2;
                break;
                case '-': result = oper1 - oper2;
                break;
                case '*': result = oper1 * oper2;
                break;
                case '/': result = oper1 / oper2;
                break;
                default :printf("Invalid operator.");
                exit(1);
            }
            push(&s,result);
        }
    }
    return pop(&s);
}

int main()
{
    char postfix[max];
    printf("Enter a postfix expression : ");
    gets(postfix);

    int result = evaluate(postfix);
    printf("Result : %d\n", result);
    return 0;
}
