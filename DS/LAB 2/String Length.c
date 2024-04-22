#include<stdio.h>
int main()
{
    char str[100];
    int length = 0;
    printf("Enter a String : ");
    gets(str);

    while(str[length] != '\0'){
        length++;
    }

    printf("The length of String is : %d", length);
    return 0;

}
