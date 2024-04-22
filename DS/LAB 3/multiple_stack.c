#include<stdio.h>
#include<stdlib.h>

#define max_stack 3
#define max_size 100

struct stack
{
    int top[max_stack];
    int a[max_stack][max_size];
};

void initialize(struct stack *s)
{
    for(int i=0;i<max_size;i++)
    {
        s->top[i] = -1;
    }
}

int isEmpty(struct stack *s,int stackno)
{
    return s->top[stackno] == -1;
}

int isFull(struct stack *s,int stackno)
{
    return s->top[stackno] == (max_size - 1);
}

void push(struct stack *s,int stackno,int val)
{
    if(isFull(s,stackno))
    {
        printf("OverFlow");
        return;
    }
    else{
        s->top[stackno]++;
        s->a[stackno][s->top[stackno]] = val;
    }
}

int pop(struct stack *s,int stackno)
{
    if(isEmpty(s,stackno)){
        printf("UnderFlow");
        return -1;
    }
    else{
        int val = s->a[stackno][s->top[stackno]];
        s->top[stackno]--;
        return val;
    }
}

int display(struct stack *s,int stackno)
{
    if(isEmpty(s,stackno)){
        printf("UnderFlow");
        return -1;
    }
    else{
    printf("Elements in stack %d is : ", stackno);
    for(int i=0;i <= s->top[stackno];i++)
    {
        printf("%d ", s->a[stackno][i]);
    }
    printf("\n");
    }
}

void main()
{
    struct stack s;
    initialize(&s);
    int sn,choice,value;

    do {
        printf("\nEnter Stack no. : ");
        scanf("%d", &sn);
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s,sn,value);
                break;
            case 2:
                pop(&s,sn);
                printf("Popped is : %d \n", pop(&s,sn));
                break;
            case 3:
                display(&s,sn);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);

}