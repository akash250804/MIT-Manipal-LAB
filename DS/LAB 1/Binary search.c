#include<stdio.h>
int binarySearch(int arr[10], int size, int element)
{
    int low,mid,high;
    low=0;
    high=size-1;

    for(int i=0;i<size;i++){
        mid=(low+high)/2;
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low=mid+1;
        }
        else
            high=mid-1;
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
    int searchIndex=binarySearch(arr,size,element);
    printf("The element %d is found at Index %d ", element, searchIndex);

    return 0;

}
