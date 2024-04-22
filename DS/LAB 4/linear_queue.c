#include<stdio.h>
#define max 6

struct linearQueue{
    int arr[max];
    int f,r;
};

struct linearQueue q;

void initialize(){
    q.f=-1;
    q.r=-1;
}

void enqueue(int val){
    if(q.r==max-1){
        printf("Overflow....\n\n");
        return ;
    }
    printf("Enter a number to enqueue : ");
    scanf("%d", &val);
    q.arr[++q.r]=val;
    }

void dequeue(){
    if(q.r==q.f){
    printf("Underflow....\n\n");
    return;
    }
    printf("Dequeued : ");
    printf("%d\n", q.arr[++q.f]);
}

void display(){
    if(q.r==q.f){
    printf("Underflow....\n\n");
    return;
    }
    printf("Values are : ");
    for(int i=q.f+1;i<=q.r;i++){
        printf("%d ", q.arr[i]);
    }
    printf("\n");
}

int main()
{
    struct linearQueue q;
    initialize();
    int choice,value;

    do{
        printf("Enter :\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
        printf("Enter your Choice : ");
        scanf("%d", &choice);

        switch (choice){
            case 1:enqueue(value);
            break;
            case 2:dequeue();
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
