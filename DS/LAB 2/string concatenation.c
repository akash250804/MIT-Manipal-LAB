#include<stdio.h>
int main()
{
    char str1[100],str2[100];
    int i=0,j=0;
    printf("Enter first String : ");
    gets(str1);
    printf("Enter Second String : ");
    gets(str2);

    while(str1[i] != '\0')
    i++;
    while(str2[j] != '\0'){
        str1[i]=str2[j];
        j++;
        i++;
    }
    str1[i] = '\0';


    printf("The concatenation of String is : %s", str1);
    return 0;

}
