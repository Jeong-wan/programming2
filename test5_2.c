#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct info{
    char name[20];
    double score;
    int credit;
};

int input_data(struct info* students, int num);
int scholarship(struct info* students, int num);
int main()
{
    struct info students[5];
    input_data(students,5);
    scholarship(students,5);
    return 0;
}
int input_data(struct info* students,int num)
{
    if(students==NULL)
    {
	printf("error: null pointer\n");
	return -1;
    }
    for(int i=0;i<num;i++)
    {
	printf("학생%d의 정보를 입력하세요\n",i+1);
	scanf("%s %lf %d",(students+i)->name,&(students+i)->score,&(students+i)->credit);
    }
}
int scholarship(struct info* students,int num)
{
    int chk=0;
    if(students==NULL)
    {
	printf("error: null pointer\n");
	return -1;
    }
    printf("========장학생 명단========\n");
    printf("이름  평점평균  수강학점\n");
    for(int i=0;i<num;i++)
    {
	if((students+i)->score >=4.3 && (students+i)->credit>=20)
	{
	    
	    printf("%-5s %-8.2lf %d\n",(students+i)->name,(students+i)->score,(students+i)->credit);
	    chk=1;
	}
    }
    if(chk==0)
	printf("장학생은 없습니다.\n");
}

