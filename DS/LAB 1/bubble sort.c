#include<stdio.h>
int main()
{
    int a[10],i,n,temp;
    printf("Enter no. of elements : ");
    scanf("%d", &n);
    printf("Enter the elements : ");

    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

     for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }

    for(i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    printf("\n");
    printf("The sorted array is : \n");

    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }

    return 0;
}

