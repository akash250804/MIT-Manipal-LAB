#include <stdio.h>
#include <string.h>

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0

struct Stack {
    int top;
    int array[MAXSIZE];
} st;

void initialize() {
 st.top=-1;
}

int isFull() {
    if(st.top==MAXSIZE-1)
        return TRUE;
    else
        return FALSE;
}

int isEmpty() {
 if(st.top==-1)
     return TRUE;
 else
     return FALSE;
}

void push(int num) {
    if (isFull())
        printf("Stack is Full...\n");
    else {
        st.array[st.top + 1]=num;
        st.top++;
    }
}

int pop() {
    if (isEmpty())
        printf("Stack is Empty...\n");
    else {
     st.top=st.top-1;
        return st.array[st.top+1];
    }
}

int main() {
    char inputString[100], c;
    int i, length;
    initialize();
    printf("Enter a string : ");
    gets(inputString);
    length = strlen(inputString);

    for(i=0;i<length;i++){
        push(inputString[i]);
    }

    for(i=0;i<length;i++){
        if(pop()!=inputString[i]) {
            printf("\n%s is not a Palindrome String\n", inputString);
            return 0;
        }
    }

    printf("\n%s is a Palindrome String\n", inputString);
    return 0;
}
