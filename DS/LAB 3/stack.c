#include<stdio.h>
#define max 6

struct stack{
    int arr[max];
    int top;
};

struct stack s;

void initialize(){
    s.top=-1;
}

void push(int num) {
    if (s.top==max-1){
        printf("Overflow....\n\n");
        return ;
    }
    else {
        printf("Enter a value to push : ");
        scanf("%d", &num);
        s.arr[s.top + 1]=num;
        s.top++;
    }
}

int pop() {
    if (s.top==-1){
        printf("Underflow....\n\n");
        return ;
    }
    else {
        printf("Popped : ");
        s.top=s.top-1;
        printf("%d\n", s.arr[s.top+1]);
    }
}

void display(){
    if(s.top==-1){
    printf("Underflow....\n\n");
    return;
    }
    printf("Values are : ");
    for(int i=s.top;i>=0;i--){
        printf("%d ", s.arr[i]);
    }
    printf("\n");
}

int main()
{
    struct stack s;
    initialize();
    int choice,value;

    do{
        printf("Enter :\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
        printf("Enter your Choice : ");
        scanf("%d", &choice);

        switch (choice){
            case 1:push(value);
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            case 4:printf("Exiting the program...");
            break;
            default:printf("Invalid choice.");
            break;
        }
    }while(choice!=4);

        return 0;
}

