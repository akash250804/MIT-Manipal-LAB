#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define max 100

struct stack
{
    char a[max];
    int top;
}s;

void push(char item)
{
    if(s.top == max-1)
    {
        printf("stack overflow\n");
        return;
    }
    s.top++;
    s.a[s.top]=item;
}

char pop()
{
    if(s.top == -1)
    {
        printf("stack underflow\n");
        return -1;
    }
    char item=s.a[s.top];
    s.top--;
    return item;
}

int isoperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
    return 1;
    else
        return 0;
}

int isoperand(char c)
{
    if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9'))
        return 1;
    else
        return 0;
}

int precedence(char op)
{
    if(op == '+'||op == '-')
        return 1;
    if(op == '*'||op == '/')
        return 2;
    if(op == '^')
        return 3;
    return 0;
}

void convert(char infix[],char prefix[])
{
    int i=0,j=0;
    char c,item;
    push('#');
    while( (c=infix[i++]) != '\0')
    {
        if(c == ')')
            push(c);
        else if(isoperand(c))
                prefix[j++]=c;
            else
                if(c == '(')
                {
                    while(s.a[s.top]!= ')')
                        prefix[j++]=pop();
                        item=pop();
                }
                else
                {
                    while( precedence(s.a[s.top])>= precedence(c))
                        prefix[j++]=pop();
                    push(c);
                }
    }
    while(s.a[s.top]!= '#')
        prefix[j++]=pop();
    prefix[j]='\0';
    strrev(prefix);
}

int main()
{
    s.top = -1;
    char c;
    char infix[max],prefix[max];
    printf("Enter a Infix expression : ");
    gets(infix);
    strrev(infix);
    convert(infix,prefix);
    printf("The prefix expression is : %s\n",prefix);
}