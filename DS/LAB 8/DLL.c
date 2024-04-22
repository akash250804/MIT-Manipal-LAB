#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node* next;
    struct node* pre;
}node;

node* createNode(int info)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->info = info;
    newNode->next = NULL;
    newNode->pre = NULL;
    return newNode;
}

node* insert(node* start,int info)
{
    node* newnode = createNode(info);
    if(start == NULL){
        start = newnode;
        return start;
    }
    node* c = start;
    while(c->next != NULL)
    {
        c = c->next;
    }
    c->next = newnode;
    newnode->pre = c;
    return start;
}

node* del_rear(node* start)
{
    if(start == NULL){
        printf("List is Empty.\n");
        return start;
    }
    node* c = start;
    node* p = NULL;
    while(c->next != NULL)
    {
        p=c;
        c=c->next;
    }
    if(p!=NULL)
        p->next = NULL;
    free(c);
    return start;
}

node* reverse(node* start)
{
    node* c = start;
    node* temp = NULL;
    while (c != NULL) {
        temp = c->pre;
        c->pre = c->next;
        c->next = temp;
        c = c->pre;
    }
    if (temp != NULL) {
        start = temp->pre;
    }
    return start;
}

node* ins_after_node(node* start, int node_ele, int info)
{
    node* newnode = createNode(info);
    node* c = start;
    while (c != NULL && c->info != node_ele) {
        c = c->next;
    }
    if (c == NULL) {
        printf("Node with value %d not found.\n", node_ele);
        return start;
    }

    newnode->next = c->next;
    if (c->next != NULL)
        c->next->pre = newnode;
    c->next = newnode;
    newnode->pre = c;
    return start;
}

node* ins_before_node(node* start, int node_ele, int info)
{
    node* newnode = createNode(info);
    if (start == NULL) {
        printf("Linked list is empty, cannot insert before node with value %d.\n", node_ele);
        return start;
    }

    if (start->info == node_ele) {
        newnode->next = start;
        start->pre = newnode;
        start = newnode;
        return start;
    }

    node* c = start->next;
    while (c != NULL && c->info != node_ele) {
        c = c->next;
    }
    if (c == NULL) {
        printf("Node with value %d not found.\n", node_ele);
        return start;
    }

    newnode->next = c;
    newnode->pre = c->pre;
    c->pre->next = newnode;
    c->pre = newnode;
    return start;
}

node* ins_at_pos(struct node* start, int pos, int info)
{
    node* newnode = createNode(info);
    if (start == NULL && pos != 1) {
        printf("Position is out of range. Cannot insert at position %d.\n", pos);
        return start;
    }

    if (pos == 1) {
        newnode->next = start;
        if (start != NULL)
            start->pre = newnode;
        start = newnode;
    }
    else {
        node* c = start;
        int i;
        for (i = 1; i < pos - 1 && c != NULL; i++) {
            c = c->next;
        }
        if (c == NULL) {
            printf("Position is out of range. Cannot insert at position %d.\n", pos);
            return start;
        }

        newnode->next = c->next;
        if (c->next != NULL)
            c->next->pre = newnode;
        c->next = newnode;
        newnode->pre = c;
    }
    return start;
}

node* delete_at_pos(struct node* start, int pos)
{
    if (start == NULL) {
        printf("Linked list is empty, nothing to delete.\n");
        return start;
    }

    if (pos == 1) {
        node* temp = start;
        start = start->next;
        if (start != NULL)
            start->pre = NULL;
        free(temp);
    }
    else {
        node* c = start;
        int i;
        for (i = 1; i < pos - 1 && c != NULL; i++) {
            c = c->next;
        }
        if (c == NULL || c->next == NULL) {
            printf("Position is out of range. Cannot delete at position %d.\n", pos);
            return start;
        }

        node* temp = c->next;
        c->next = temp->next;
        if (temp->next != NULL)
            temp->next->pre = c;
        free(temp);
    }
    return start;
}


node* display(node* start)
{
    if(start == NULL){
        printf("List is Empty.\n");
        return start;
    }
    node* c = start;
    printf("Elements are  : ");
    while(c != NULL)
    {
        printf("%d ", c->info);
        c = c->next;
    }
    printf("\n");
    return start;
}

int main()
{
    node* start = NULL;
    int info,ch,node_ele,pos;

    while(ch != -1)
    {
        printf("\nEnter\n 0.Exit.\n 1.Insert at rear.\n 2.Delete at rear.\n 3.Display.\n 4.Reverse.\n 5.Insert after.\n 6.Insert before.\n 7.Insert at position.\n 8.Delete at position.\n");
        printf("Enter your Choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 0: exit(0);
            break;

            case 1:printf("Enter the value : ");
            scanf("%d", &info);
            start = insert(start,info);
            break;

            case 2:start = del_rear(start);
            break;

            case 3:start = display(start);
            break;

            case 4:start = reverse(start);
            printf("Reversed ");
            start = display(start);
            break;

            case 5:printf("Enter the Node to insert after : ");
            scanf("%d", &node_ele);
            printf("Enter the value to insert : ");
            scanf("%d", &info);
            start = ins_after_node(start,node_ele,info);
            break;

            case 6:printf("Enter the Node to insert before : ");
            scanf("%d", &node_ele);
            printf("Enter the value to insert : ");
            scanf("%d", &info);
            start = ins_before_node(start,node_ele,info);
            break;

            case 7:printf("Enter the position : ");
            scanf("%d",&pos);
            printf("Enter the value : ");
            scanf("%d",&info);
            start = ins_at_pos(start,pos,info);
            break;

            case 8:printf("Enter the position : ");
            scanf("%d",&pos);
            start = delete_at_pos(start,pos);
            break;

            default:printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}
