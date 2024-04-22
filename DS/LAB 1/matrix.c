#include <stdio.h>
int main()
{
    int a[100][100],b[100][100],c[100][100],m,n,i,j;
    printf("Enter no. of rows and columns in matrix:");
    scanf("%d%d",&m,&n);

    printf("Enter element of Matrix A : ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter element of Matrix B : ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&b[i][j]);
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[i][j]>b[i][j]){
                c[i][j]=a[i][j];
            }
            else{
                c[i][j]=b[i][j];
            }
        }
    }

    printf("Matrix C[Max] is : \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
