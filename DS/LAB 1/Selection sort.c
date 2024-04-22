#include<stdio.h>
int main()
{

    int arr[10],i,n,position,swap;
    printf("Enter no. of elements : ");
    scanf("%d", &n);
    printf("Enter the elements : ");

    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

     for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

for (i = 0; i < (n - 1); i++) {
      position = i;
      for (int j = i + 1; j < n; j++) {
         if (arr[position] > arr[j])
            position = j;
      }
      if (position != i) {
         swap = arr[i];
         arr[i] = arr[position];
         arr[position] = swap;
      }
   }

   printf("\n");
    printf("The sorted array is : \n");

    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}
