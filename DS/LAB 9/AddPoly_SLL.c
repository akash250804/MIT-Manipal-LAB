#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int coeff;
    int expo;
    struct node *next;
}node;

node *read(node *p);
node *attach(int c,int e,node *p);
void display(node *p);
node *add_poly(node *a,node *b);

node *read(node *p)
{
  int expo,coeff;
  while(1)
  {
      printf("Enter the coefficient (-999 to exit) : ");
      scanf("%d",&coeff);
      if(coeff == -999)
        break;
      printf("Enter the exponent : ");
      scanf("%d",&expo);
      p = attach(coeff,expo,p);
  }
  return p;
}

node *attach(int c,int e,node *p)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->coeff = c;
    temp->expo = e;
    temp->next = NULL;

    if(p == NULL){
        p = temp;
        return p;
    }
    node *cur = p;
    while(cur->next != NULL)
        cur = cur->next;
        cur->next = temp;
        return p;
}

void display(node *p)
{
    while(p != NULL)
    {
        printf("%dx^%d", p->coeff,p->expo);
        p = p->next;

        if(p != NULL)
            printf("+ ");
    }
    printf("\n");
}

node *add_poly(node *a,node *b)
{
    node *p = NULL;
    while(a != NULL && b != NULL)
    {
        if(a->expo > b->expo)
        {
            p = attach(a->coeff,a->expo,p);
            a = a->next;
        }
        else if(a->expo < b->expo)
        {
            p = attach(b->coeff,b->expo,p);
            b = b->next;
        }
        else
        {
            int sum = a->coeff + b->coeff;
            if(sum != 0)
                p = attach(sum,a->expo,p);
            a = a->next;
            b = b->next;
        }
    }

    while(a != NULL)
    {
        p = attach(a->coeff,a->expo,p);
        a = a->next;
    }
    while(b != NULL)
    {
        p = attach(b->coeff,b->expo,p);
        b = b->next;
    }

    return p;
}

int main()
{
    node *p1 = NULL;
    node *p2 = NULL;
    node *p3 = NULL;

    printf("Enter polynomial 1 : \n");
    p1 = read(p1);
    printf("Enter polynomial 2 : \n");
    p2 = read(p2);

    printf("Polynomial 1 : ");
    display(p1);
    printf("Polynomial 2 : ");
    display(p2);

    p3 = add_poly(p1,p2);
    printf("Sum is : ");
    display(p3);

    return 0;
}
