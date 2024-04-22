#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node* next;
    struct node* pre;
}node;

node* createNode(node* info)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->info = info;
    newNode->next = NULL;
    newNode->pre = NULL;
    return newNode;
}

node* insert(node* start,int info)
{
    node* newNode = createNode(info);
    if(start == NULL)
    {
        start = newNode;
        return start;
    }
    node* c = start;
    while(c->next != NULL)
    {
        c = c->next;
    }
    c->next = newNode;
    newNode->pre = c;
    return start;
}

node* display(node* start)
{
    if(start == NULL)
    {
        printf("List is Empty.\n");
        return start;
    }
    printf("Values are : ");
    node* c = start;
    while(c != NULL)
    {
        printf("%d ", c->info);
        c = c->next;
    }
    printf("\n");
    return start;
}

node* concatenate(node* X1,node* X2)
{
    if(X1 == NULL)
        return X2;
    else if(X2 == NULL)
        return X1;
    else{
        node* c = X1;
        while(c->next != NULL){
            c = c->next;
        }
        c->next = X2;
        X2->pre = c;
    }
    return X1;
}

int main()
{
    node* X1 = NULL;
    node* X2 = NULL;
    int info;

    printf("Enter the values in X1 (-1 to exit) : ");
    while(1){
        scanf("%d", &info);
        if(info == -1){
        break;
        }
        X1 = insert(X1,info);
    }
    X1 = display(X1);

    printf("Enter the values in X2 (-1 to exit) : ");
    while(1){
        scanf("%d", &info);
        if(info == -1){
        break;
        }
        X2 = insert(X2,info);
    }
    X2 = display(X2);

    printf("The concatenated list is : ");
    X1 = concatenate(X1,X2);
    X1 = display(X1);

    return 0;
}
