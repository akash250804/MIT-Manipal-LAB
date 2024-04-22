#include<stdio.h>
#include<stdlib.h>
#define max 100

struct queue
{
    int s1[max],s2[max];
    int top1,top2;
};

void initialize(struct queue *q){
    q->top1 = -1;
    q->top2 = -1;
}

void push1(struct queue *q,int val){
    if(q->top1 == max-1){
        printf("OverFlow\n");
        return;
    }
    q->s1[++q->top1] = val;
}

int pop1(struct queue *q){
    if(q->top1 == -1){
        printf("UnderFlow\n");
        return -1;
    }
    return q->s1[q->top1--];
}

void push2(struct queue *q,int val){
    if(q->top2 == max-1){
        printf("OverFlow\n");
        return;
    }
    q->s2[++q->top2] = val;
}

int pop2(struct queue *q){
    if(q->top2 == -1){
        printf("UnderFlow\n");
        return -1;
    }
    return q->s2[q->top2--];
}

void enqueue(struct queue *q,int val){
    push1(q,val);
}

int dequeue(struct queue *q){
    if(q->top1 == -1 && q->top2 == -1){
        printf("Queue is empty\n");
        return -1;
    }

    if(q->top2 == -1){
        while(q->top1 != -1){
            push2(q,pop1(q));
        }
    }
    return pop2(q);
}

void display(struct queue* q) {
    if(q->top1 == -1 && q->top2 == -1){
        printf("Queue is empty\n");
        return -1;
    }
    
    printf("Queue is : ");
    for(int i=0;i<=q->top2;i++){
        printf("%d ", q->s2[i]);
    }   
    for(int i=q->top1;i>=0;i--){
        printf("%d ", q->s1[i]);
    }
    printf("\n");
}

int main()
{
    struct queue q;
    initialize(&q);
    int choice,value;

    // enqueue(&q,1);
    // enqueue(&q,2);
    // enqueue(&q,3);

    // printf("Dequeued : %d\n",dequeue(&q));
    // printf("Dequeued : %d\n",dequeue(&q));

    // enqueue(&q,4);
    // printf("Dequeued : %d\n",dequeue(&q));

    do{
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                //dequeue(&q);
                printf("Dequeued : %d\n", dequeue(&q));
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);
    

    return 0;
}

