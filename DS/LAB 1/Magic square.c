#include<stdio.h>
int main()
{

    int a[10][10],i,j,m,n,flag=0;
    int sum,sum1,sum2;
    printf("Enter no. of rows and columns : ");
    scanf("%d%d", &m,&n);
    printf("Enter the elements : ");

    for(i=0;i<m;i++){
       for(j=0;j<n;j++){
         scanf("%d", &a[i][j]);
       }
    }

     for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    sum=0;
    for(i=0;i<m;i++){
       for(j=0;j<n;j++){
        if(i==j){
            sum=sum+a[i][j];
        }
       }
    }

    for(i=0;i<m;i++){
            sum1=0;
       for(j=0;j<n;j++){
            sum1=sum1+a[i][j];
       }
            if(sum==sum1){
            flag=1;
         }
         else{
            flag=0;
         break;
         }
    }

    for(i=0;i<m;i++){
            sum2=0;
       for(j=0;j<n;j++){
            sum2=sum2+a[j][i];
       }
         if(sum==sum2){
            flag=1;
         }
         else{
            flag=0;
         break;
         }
    }

    if(flag==1){
        printf("\nThis is a magic square.");
    }
    else
        printf("\nThis is not a magic square.");

    return 0;
}

