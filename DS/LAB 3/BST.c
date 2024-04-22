#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *rcl;
    struct node *lcl;
}node;

typedef struct QueueNode
{
    node *data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *front, *rear;
} Queue;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, node *data)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

node *dequeue(Queue *queue)
{
    if (queue->front == NULL)
        return NULL;

    QueueNode *temp = queue->front;
    node *data = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return data;
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
    if(root == NULL)
    {
        root = newNode;
        return root;
    }
      node *cur = root;
      node *p = root;
        while(cur != NULL)
        {
            if(newNode->info == cur->info){
                printf("Error.\n");
                free(newNode);
                return root;
            }
            if(newNode->info < cur->info){
                p = cur;
                cur = cur->lcl;
            }
            else{
                p = cur;
                cur = cur->rcl;
            }
        }
        if(newNode->info < p->info){
                p->lcl = newNode;
        }
        else{
                p->rcl = newNode;
        }
        return root;
}

node *del(node *root,int ele)
{
    node *par;
    node *cur;
    node *succ;

    if(root == NULL)
        return root;

    par=cur=NULL;
    node*q = root;

    while(q!=NULL)
    {
        if(q->info == ele){
            cur = q;
            break;
        }
        par=q;
        if(q->info > ele)
            q=q->lcl;
        else
            q=q->rcl;
    }

    if(q==NULL){
        printf("Element not found.\n");
        return root;
    }

    if(cur->lcl != NULL && cur->rcl != NULL){
        par = cur;
        succ = cur->rcl;
        while(succ->lcl != NULL){
            par = succ;
            succ = succ->lcl;
        }
        cur->info = succ->info;
        cur = succ;
    }

    if(cur->lcl == NULL && cur->rcl == NULL){
        if(par->rcl == cur)
            par->rcl = NULL;
        else
            par->lcl = NULL;
        free(cur);
        return root;
    }

    if(cur->lcl == NULL && cur->rcl != NULL){
        if(par->lcl == cur)
            par->lcl = cur->rcl;
        else
            par->rcl = cur->rcl;
        free(cur);
        return root;
    }

    if(cur->lcl != NULL && cur->rcl == NULL){
        if(par->lcl == cur)
            par->lcl = cur->lcl;
        else
            par->rcl = cur->lcl;
        free(cur);
        return root;
    }
}

node *search(node *root, int ele)
{
    if (root == NULL || root->info == ele)
        return root;

    if (ele < root->info)
        return search(root->lcl, ele);

    return search(root->rcl, ele);
}

void inorder(node *root)
{
    if(root)
    {
        inorder(root->lcl);
        printf("%d ", root->info);
        inorder(root->rcl);
    }
}

void levelOrder(node *root)
{
    if (root == NULL)
        return;

    Queue *queue = createQueue();
    enqueue(queue, root);

    while (queue->front != NULL)
    {
        node *current = dequeue(queue);
        printf("%d ", current->info);

        if (current->lcl != NULL)
            enqueue(queue, current->lcl);

        if (current->rcl != NULL)
            enqueue(queue, current->rcl);
    }

    free(queue);
}

int main()
{
    node *root = NULL;
    int ch,info;
    while(1)
    {
        printf("Enter.\n 0.Exit.\n 1.Insert.\n 2.Delete.\n 3.Search the element.\n 4.Traverse in InOrder.\n 5.Level Order.\n");
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

            case 2:printf("Enter a number : ");
            scanf("%d", &info);
            root = del(root,info);
            break;

            case 3:printf("Enter a number to search: ");
            scanf("%d", &info);
            node *result = search(root, info);
            if (result != NULL)
                printf("Element %d found in the BST.\n", info);
            else
                printf("Element %d not found in the BST.\n", info);
            break;

            case 4:printf("InOrder Values are : ");
            inorder(root);
            printf("\n");
            break;

            case 5:printf("Level order : ");
            levelOrder(root);
            printf("\n");
            break;

            default :printf("Invalid Choice.\n");
            break;
        }
    }
    return 0;
}
