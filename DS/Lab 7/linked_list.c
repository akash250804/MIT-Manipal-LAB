#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node * next;
}node;

node* createNode(int info);
node* insert(node* start, int info);
node* delete(node* start,int info);
node* ins_beg(node* start,int info);
node* del_beg(node* start);
node* del_end(node* start);
node* rev(node* start);
node* del_alter(node * start);
node* bubbleSort(node* start);
node* insertSorted(node* start, int info);
void traverse(node* start);
 
node* createNode(int info)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->info = info;
    newNode->next = NULL;
    return newNode;
}

node* insert(node* start, int info)
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


node* delete(node* start,int info)
{
    if(start == NULL){
        printf("Linked list is empty.\n");
        return NULL;
    }

    node* cur = start;
    node* pre = NULL;

    while(cur != NULL && cur->info != info){
        pre = cur;
        cur = cur->next;
    }

    if(cur == NULL){
        printf("Element not found.\n");
        return start;
    }

    if(pre == NULL){
        start = cur->next;
    }
    else{
        pre->next = cur->next;
    }

    free(cur);
    printf("Element deleted successfully.\n");
    return start;
}

node* ins_beg(node* start,int info)
{
    node* newNode = createNode(info);
    newNode->next = NULL;

    if(start == NULL){
        start = newNode;
        return start;
    }
    newNode->next = start;
    start = newNode;
    return start;
    
}

node* del_beg(node* start)
{
    if(start == NULL){
        printf("Nothing to delete.\n");
        return NULL;
    }
    node* temp=start;
    start = start->next;
    free(temp);
    return start;
}

node* del_end(node* start)
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

node* rev(node* start)
{
    if(start == NULL){
        printf("Empty list.\n");
        return NULL;
    }
    node *p;
    node *q;
    node *r;
    q=r=NULL;
    p=start;

    while(p != NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    start = q;
    return q;
}

node* del_alter(node * start)
{
    node *cur = start;
    node *pre = NULL;

    while (cur != NULL && cur->next != NULL)
    {
        node* temp = cur->next;
        cur->next = temp->next;
        free(temp);

        pre = cur;
        cur = cur->next;
    }
    return start;
}

node* bubbleSort(node* start)
{
    if (start == NULL || start->next == NULL) {
        // Empty list or a single element, no need to sort.
        return start;
    }

    int swapped;
    node* ptr1;
    node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr) {
            if (ptr1->info > ptr1->next->info) {
                // Swap the data of the current and next nodes.
                int temp = ptr1->info;
                ptr1->info = ptr1->next->info;
                ptr1->next->info = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return start;
}

node* insertSorted(node* start, int info)
{
    node* newNode = createNode(info);

    if (start == NULL || info <= start->info)
    {
        newNode->next = start;
        start = newNode;
    }
    else
    {
        node* current = start;
        while (current->next != NULL && current->next->info < info)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    return start;
}


void traverse(node* start)
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
        printf("\nEnter.\n1.Insert\n2.Delete.\n3.Insert from beginning.\n4.Delete from beginning.\n5.Delete from end.\n6.Reverse the list.\n7.Delete alter elements.\n8.Sort the list.\n9.Insert element in sorted list.\n10.Traverse.\n11.Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1: printf("Enter the element to insert : ");
            scanf("%d", &info);
            start = insert(start,info);
            break;

            case 2: printf("Enter element to delete : ");
            scanf("%d", &info);
            start = delete(start,info);
            break;

            case 3:
            printf("Enter the element to insert from beginning : ");
            scanf("%d", &info); 
            start = ins_beg(start,info);
            break;

            case 4: start = del_beg(start);
            //printf("Deleted : %d", start);
            break;

            case 5: start = del_end(start);
            break;

            case 6: start = rev(start);
            printf("List Reversed Successfully\n");
            printf("Reversed ");
            traverse(start);
            break;

            case 7: start = del_alter(start);
            printf("Deleted alter elements successfully.\n");
            printf("Alter deleted ");
            traverse(start);
            break;

            case 8:
            start = bubbleSort(start);
            printf("List Sorted Successfully\n");
            printf("Sorted ");
            traverse(start);
            break;

            case 9: 
            printf("Enter the element to insert in sorted order: ");
            scanf("%d", &info);
            start = insertSorted(start, info);
            break;

            case 10:traverse(start);
            break; 

            case 11: printf("Exiting the program.\n");
            break;
            
            default: printf("Invalid choice.\n");
            break;
        }
    }
    while(ch != 11);
    return 0;
}
