#include <stdio.h>

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0

struct Stack {
    int top;
    int items[MAXSIZE];
};

void initialize(struct Stack *stack) {
    stack->top=-1;
}

int isFull(struct Stack *stack) {
    if(stack->top==MAXSIZE-1){
            return TRUE;
    }else{
        return FALSE;
    }
}

int isEmpty(struct Stack *stack) {
    if(stack->top==-1){
            return TRUE;
    }else{
        return FALSE;
    }
}

void push(struct Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
    } else {
        stack->top++;
        stack->items[stack->top]=item;
    }
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
    } else {
        int item=stack->items[stack->top];
        stack->top--;
        return item;
    }
}

void convertToBinary(int decimal,int base) {
    struct Stack stack;
    initialize(&stack);

    printf("\nDecimal %d to base %d is : ", decimal,base);

    while (decimal>0) {
        push(&stack,decimal%base);
        decimal/=base;
    }

    while (!isEmpty(&stack)) {
        int hexaDigit=pop(&stack);
        if (hexaDigit<10) {
            printf("%d", hexaDigit);
        } else {
            printf("%c",'A'+(hexaDigit-10));
        }
    }
    printf("\n");
}

int main() {
    int decimal,base;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    printf("\nEnter a base : ");
    scanf("%d", &base);

    convertToBinary(decimal,base);
    return 0;
}
