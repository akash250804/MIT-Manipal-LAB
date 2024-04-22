#include<stdio.h>
int linearSearch(int arr[10], int size, int element)
{
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[10],size,i;
    printf("Enter the no of elements : ");
    scanf("%d", &size);
    printf("Enter the elements : ");

    for(i=0;i<size;i++){
        scanf("%d", &arr[i]);
    }

     for(i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }

    printf("\n");

    int element;
    printf("Enter the element to search : ");
    scanf("%d", &element);
    int searchIndex=linearSearch(arr,size,element);
    printf("The element %d is found at Index %d ", element, searchIndex);

    return 0;

}
