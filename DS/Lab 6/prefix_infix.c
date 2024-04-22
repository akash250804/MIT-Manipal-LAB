#include<stdio.h>
#include<string.h>

#define max 100

struct stack{
    char a[max][max];
    int top;
}s;

void push(char sym[]){
    if(s.top == max-1)
    printf("Stack Overflow...");
    else{
        s.top++;
        strcpy(s.a[s.top],sym);
    }
}

char *pop(){
    if(s.top == -1)
    printf("Stack Underflow...");
    else{
        char str[max];
        return s.a[s.top--];
    }
}

void pretoinfix(){
    char pfix[max],sym[2],op1[10],op2[10],res[max];
    int i;
    printf("Enter prefix expression : ");
    gets(pfix);
    strrev(pfix);

    for(i=0;pfix[i] != '\0'; i++){
        sym[0]=pfix[i];
        sym[1]='\0';
        if(sym[0] == '+' || sym[0] == '-' || sym[0] == '*' || sym[0] == '/'){
            strcpy(op2,pop());
            strcpy(op1,pop());
            strcpy(res,")");
            strcat(res,op1);
            strcat(res,sym);
            strcat(res,op2);
            strcat(res,"(");
            push(res);
        }
        else{
            push(sym);
        }
    }
    strrev(res);
    printf("The infix expression is : %s\n",res);
}

int main()
{
    s.top = -1;
    pretoinfix();
    return 0;
}