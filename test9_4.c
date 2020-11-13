#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define EMPLOYEE 20
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
    if((fp=fopen("employee.txt","rb"))==NULL)
    {
	printf("read error");
	exit(-1);
    }
    worker* w=(worker*)malloc(sizeof(worker)*EMPLOYEE);
    check=fread(w,sizeof(worker),1,fp);
    while(check)
    {
	printf("%d번째 직원 : %s %d %d %d\n",i+1,w[i].name,w[i].id,w[i].age,w[i].salary);
        i++;
	check=fread(&w[i],sizeof(worker),1,fp);
    }
    
    fclose(fp);
    
    return 0;
}

