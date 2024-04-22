#include<stdio.h>

struct student{
    int roll_no,marks;
    char name[25];
}stud[100],t;

void readInfo(int i,int n){
     printf("Enter Roll_no , name , grade of student : ");
     for(i=0;i<n;i++){
        scanf("%d%s%d", &stud[i].roll_no,stud[i].name,&stud[i].marks);
    }
}

void sort(int i, int j,int n){
     for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(stud[j].roll_no>stud[j+1].roll_no){
                t=stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=t;
            }
        }
    }
}
void display(int i,int n){
    printf("The list of students on the basis of their marks : \n");
    printf("Roll_no\t\tName\t\tGrade\n");

    for(i=0;i<n;i++){
        printf("%d\t\t%s\t\t%d\n", stud[i].roll_no,stud[i].name,stud[i].marks);
    }
}

int main()
{
    int n,i,j;
    printf("Enter no. of students : ");
    scanf("%d", &n);

   readInfo(i,n);
   sort(i,j,n);
   display(i,n);

    return 0;
}
