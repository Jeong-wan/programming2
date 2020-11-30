#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define EMPLOYEE 20
#define HOW_MANY 6
typedef struct worker{
    char name[10];
    int id;
    int age;
    int salary;
}worker;
int main(){
    FILE *fp;
    int check;
    int i=0;
    if((fp=fopen("employee.txt","w"))==NULL)
    {
	printf("write error");
	exit(-1);
    }
    worker* w=(worker*)malloc(sizeof(worker)*EMPLOYEE);
    for(int i=0;i<HOW_MANY;i++)
    {
	scanf("%s %d %d %d",w[i].name,&w[i].id,&w[i].age,&w[i].salary);
       fprintf(fp,"%s %d %d %d",w[i].name,w[i].id,w[i].age,w[i].salary);
    }
   // fwrite(w,sizeof(worker),HOW_MANY,fp);
    fclose(fp);
    
    return 0;
}

