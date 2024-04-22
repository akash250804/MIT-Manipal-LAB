#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int info;
    struct node *rcl;
    struct node *lcl;
}node;

node *createnode(int info)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->rcl = newNode->lcl = NULL;
    newNode->info = info;
    return newNode;
}

node *insert(node *root,int info)
{
    node *newNode = createnode(info);
    if(root == NULL){
        root = newNode;
        return root;
    }
    char d[100];
    printf("Enter the direction : ");
    scanf("%s", &d);
    node *c = root;
    node *p = NULL;
    int i;
    for(i=0;i<strlen(d);i++)
    {
        if(c == NULL)
            break;
        p=c;
        if(d[i] == 'l')
            c = c->lcl;
        else
            c = c->rcl;
    }
    if(c != NULL || i != strlen(d)){
        printf("Error.\n");
        free(newNode);
        return root;
    }
    if(d[i-1] == 'l')
        p->lcl = newNode;
    else
        p->rcl = newNode;
    return root;
}

void inorder(node *root)
{
    if(root){
        inorder(root->lcl);
        printf("%d ", root->info);
        inorder(root->rcl);
    }
}

int main()
{
    node *root = NULL;
    int info,ch;
    while(1)
    {
        printf("\nEnter.\n 0.Exit.\n 1.Insert.\n 2.Display.\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 0:exit(0);
            break;

            case 1:printf("Enter a number : ");
            scanf("%d", &info);
            root = insert(root,info);
            break;

            case 2:inorder(root);
            break;

            default :printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}
