#include<stdio.h>
int main()
{
    int a[100],i,n,key,j;
    printf("enter number of elements\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

        for(i=0;i<n;i++){
        printf("%d\t",a[i]);
        }

        printf("\n");

    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && key<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    printf("Array after insertion is\n");
    for(i=0;i<n;i++){
        printf("%d\t", a[i]);
    }

    return 0;

}
