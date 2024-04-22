#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node * next;
}node;

node* createNode(int info)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->info = info;
    newNode->next = NULL;
    return newNode;
}

node* push(node* start, int info)
{
    node* newNode = createNode(info);

    if (start == NULL)
    {
        start = newNode;
    }
    else
    {
        node* current = start;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    return start;
}

node* pop(node* start)
{
    if(start == NULL){
        printf("Nothing to delete.\n");
        return NULL;
    }
    node* cur = start;
    node* prev = NULL;

    while(cur->next != NULL){
        prev = cur;
        cur = cur->next;
    }
    free(cur);
    prev->next = NULL;
    return start;
}

void display(node* start)
{
    if(start == NULL){
        printf("Linked list is empty.\n");
        return;
    }
    node* cur = start;
    printf("Linked list elements : ");
    while(cur != NULL){
        printf("%d ", cur->info);
        cur = cur->next;
    }
    printf("\n");
}

int main()
{
    node* start = NULL;
    int info,ch;

    do{
        printf("\nEnter.\n1.Push\n2.Pop.\n3.Display.\n4.Exit.\n");
        scanf("%d", &ch);

        switch(ch){
            case 1: printf("Enter the element to push : ");
            scanf("%d", &info);
            start = push(start,info);
            break;

            case 2: start = pop(start);
            break;

            case 3:display(start);
            break; 

            case 4: printf("Exiting the program.\n");
            break;
            
            default: printf("Invalid choice.\n");
            break;
        }
    }
    while(ch != 4);
    return 0;
}
