#include<stdio.h>
int main()
{
    char str1[100],str2[100];
    int i;
    printf("Enter first String : ");
    gets(str1);
    printf("Enter second String : ");
    gets(str2);

    for(i=0;str1[i]==str2[i] && str1[i]!=0;i++);

    if(str1[i]!=str2[i]){
        printf("Both Strings are not same");
    }
    else{
        printf("Both Strings are same");
    }

    return 0;
}
