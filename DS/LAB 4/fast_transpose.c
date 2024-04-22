#include<stdio.h>
#define max 100

struct element
{
    int row;
    int col;
    int value;
};

int read(struct element a[],int *row,int *col)
{
    printf("Enter no. of rows and columns : ");
    scanf("%d %d", row,col);

    int nonZero;
    printf("Enter no. of non zero elements : ");
    scanf("%d", &nonZero);

    printf("Enter elements (row col value) : \n");
    for(int i=0;i<nonZero;i++){
        scanf("%d %d %d", &a[i].row,&a[i].col,&a[i].value);
    }
    return nonZero;
}

void display(struct element a[],int nonZero)
{
    printf("Sparce matrix : \n");
    for(int i=0;i<nonZero;i++){
        printf("%d %d %d\n", a[i].row,a[i].col,a[i].value);
    }
}

void fast(struct element a[],struct element t[],int rows,int cols,int nonZero)
{
    int rowterm[cols],postion[cols];

    for(int i=0;i<cols;i++){
        rowterm[i] = 0;
    }

    for(int i=0;i<nonZero;i++){
        rowterm[a[i].col]++;
    }

    postion[0]=0;

    for(int i=1;i<cols;i++){
        postion[i] = postion[i-1] + rowterm[i-1];
    }

    for(int i=0;i<nonZero;i++){
        int j=postion[a[i].col]++;
        t[j].row=a[i].col;
        t[j].col=a[i].row;
        t[j].value=a[i].value;
    }
}

void main()
{
    struct element a[max];
    struct element t[max];
    int row,col,value;

    value = read(a,&row,&col);
    display(a,value);
    fast(a,t,row,col,value);
    display(a,value);

}