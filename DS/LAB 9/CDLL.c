#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
    struct node *pre;
}node;

node *createnode(int info)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->info = info;
    newNode->next = newNode;
    newNode->pre = newNode;
    return newNode;
}

node *insert(node *start,int info)
{
    node *newNode = createnode(info);
    if(start == NULL){
        start = newNode;
        return start;
    }else{
    newNode->next = start;
    newNode->pre = start->pre;
    start->pre->next = newNode;
    start->pre = newNode;
    return start;
    }
}

node *del(node *start,int info)
{
    node *newNode = createnode(info);
    if(start == NULL)
    {
        printf("List is Empty.\n");
        return start;
    }
    else{
        node *cur = start;
        do{
            if(cur->info == info){
                if(cur->next == cur){
                    free(cur);
                    start = NULL;
                }
                else{
                    cur->pre->next = cur->next;
                    cur->next->pre = cur->pre;
                    if(cur == start){
                        start = cur->next;
                    }
                    free(cur);
                }
                printf("Deleted : %d", info);
                return start;
            }
            cur = cur->next;
        }while(cur != start);
        printf("Number not found.\n");
    }
    return start;
}

node *display(node *start)
{
    if(start == NULL){
        printf("List is Empty.\n");
        return start;
    }
    node *cur = start;
    printf("Circular List Values are : ");
    do{
        printf("%d ",cur->info);
        cur = cur->next;
    }while(cur != start);
    printf("\n");
    return start;
}

int main()
{
    node *start = NULL;
    int ch,info;
    while(1)
    {
        printf("\nEnter.\n 0.Exit.\n 1.Insert.\n 2.Delete.\n 3.Display.\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:exit(0);
            break;

            case 1:printf("Enter a Number : ");
            scanf("%d", &info);
            start = insert(start,info);
            break;

            case 2:printf("Enter a Number to delete: ");
            scanf("%d", &info);
            start = del(start,info);
            break;

            case 3:start = display(start);
            break;

            default: printf("Invalid Choice.\n");
            break;
        }
    }
    return 0;
}
