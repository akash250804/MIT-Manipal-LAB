#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

typedef struct node
{
    int info;
    struct node *rcl;
    struct node *lcl;
}node;

typedef struct stack
{
    int top;
    node *arr[max];
}stack;

int isempty(stack* s) {
    return (s->top == -1);
}

void push(stack *s,node *root)
{
    s->arr[++s->top] = root;
}

node *pop(stack *s)
{
    if(s->top == -1)
        return NULL;
    else
        return s->arr[s->top--];
}

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

void inorder(node *root,stack *s)
{
    for(;;){
        for(;root;root=root->lcl)
            push(s,root);
        root = pop(s);
        if(!root)
            break;
        printf("%d ",root->info);
        root = root->rcl;
    }
}

void preorder(node *root,stack *s)
{
    for(;;){
        for(;root;root=root->lcl){
            printf("%d ",root->info);
            push(s,root);
        }
        root = pop(s);
        if(!root)
            break;
        root = root->rcl;
    }
}

void postorder(node* root, stack* s) {
    node* lastVisited = NULL;
    while (root || !isempty(s)) {
        if (root) {
            push(s, root);
            root = root->lcl;
        } else {
            node* peek = s->arr[s->top];
            if (peek->rcl && lastVisited != peek->rcl) {
                root = peek->rcl;
            } else {
                printf("%d ", peek->info);
                lastVisited = pop(s);
            }
        }
    }
}

int findParent(node* root, int key, int parent) {
    if (root == NULL) {
        return -1;  // Element not found
    }

    if (root->info == key) {
        return parent;
    }

    int left = findParent(root->lcl, key, root->info);
    if (left != -1) {
        return left;
    }

    return findParent(root->rcl, key, root->info);
}

int findDepth(node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftDepth = findDepth(root->lcl);
        int rightDepth = findDepth(root->rcl);
        return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
    }
}

int printAncestors(node* root, int key) {
    if (root == NULL) {
        return 0;
    }

    if (root->info == key) {
        return 1;
    }

    if (printAncestors(root->lcl, key) || printAncestors(root->rcl, key)) {
        printf("%d ", root->info);
        return 1;
    }

    return 0;
}

int countLeafNodes(node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->lcl == NULL && root->rcl == NULL) {
        return 1;
    }

    return countLeafNodes(root->lcl) + countLeafNodes(root->rcl);
}

int main()
{
    node *root = NULL;
    stack* s = (stack*)malloc(sizeof(stack));
    s->top = -1;
    int info,ch;
    while(1)
    {
        printf("\nEnter.\n 0.Exit.\n 1.Insert.\n 2.InOrder.\n 3.PreOrder.\n 4.PostOrder.\n 5.Parent Node.\n 6.Depth of Tree.\n 7.Ancestor of Node.\n 8.Leaf node.\n");
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

            case 2:inorder(root,s);
            break;

            case 3:preorder(root,s);
            break;

            case 4:postorder(root,s);
            break;

            case 5:printf("Enter the key to find its parent: ");
                scanf("%d", &info);
                int parent = findParent(root, info, -1);
                if (parent != -1) {
                    printf("Parent of %d is %d\n", info, parent);
                } else {
                    printf("%d is the root node or not found in the tree.\n", info);
                }
            break;

            case 6:printf("Depth of the tree: %d\n", findDepth(root));
            break;

            case 7:printf("Enter the key to find its ancestors: ");
               scanf("%d", &info);
               printf("Ancestors of %d are: ",info);
               printAncestors(root, info);
               printf("\n");
            break;

            case 8:printf("Number of leaf nodes: %d\n", countLeafNodes(root));
            break;

            default :printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}
