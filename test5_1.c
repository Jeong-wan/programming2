#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    char name[10];
    char email[20];
    char num[20];
}student;
int nSearch(char *a, student *s);
int aSearch(student *s);
int main()
{
    int menu;
    char fname[10];
    student a[10];
    for(int i=0;i<10;i++)
    {
	printf("이름을 입력하세요: ");
	scanf("%s",a[i].name);
	printf("이메일을 입력하세요: ");
	scanf("%s",a[i].email);
	printf("전화번호를 입력하세요: ");
	scanf("%s",a[i].num);
    }
    while(1)
    {
    	printf("\n===========menu==========\n");
   	printf("1. 이름 검색 \n2. 전체 검색\n0. 프로그램 종료\n");
   	scanf("%d",&menu);
    	switch(menu){
	case 1:
	    printf("검색할 이름을 입력하세요: ");
	    scanf("%s",fname);
	    nSearch(fname,a);
	    break;
	case 2:
	    aSearch(a);
	    break;
	case 0:
	    printf("프로그램을 종료합니다.\n");
	    exit(0);
	default:
	    break;
    }
    }
    return 0;

}
int nSearch(char *sname, student *s)
{
    int chk=0;
    if(s==NULL)
    {
	printf("error : null pointer\n");
	return -1;
    }
    for(int i=0;i<10;i++)
    {
	if(!strcmp((s+i)->name,sname))
	{
	    printf("%s의 이메일은 %s, 전화번호는 %s 입니다.\n",(s+i)->name,(s+i)->email,(s+i)->num);
	    chk=1;
	    continue;
	}
    }
    if(chk==0)
	printf("%s 이름을 가진 친구는 없습니다.\n",sname);
}
int aSearch(student *s)
{
    if(s==NULL)
    {
	printf("error : null pointer\n");
	return -1;
    }
    for(int i=0;i<10;i++)
    {
	printf("%s의 이메일은 %s, 전화번호는 %s 입니다,\n",(s+i)->name,(s+i)->email,(s+i)->num);
    }
}

