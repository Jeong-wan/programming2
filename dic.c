#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define HOW_MANY 200
typedef struct word{
    char eng[15];
    char kor[30];
    struct word* next;
}dictionary;
typedef dictionary* LINK;
void wordTest(LINK a,int node);
int  nodeNum(LINK a);
int main()
{
    FILE *fp; 
    int menu;int i=0;
    char tempK[30]; char tempbuf[15];
    LINK *ptr;
    if(((fp=fopen("dic.txt","r"))==NULL))
    {
	printf("open error\n");
	exit(-1);
    }
    LINK head=malloc(sizeof(dictionary));
    LINK temp; LINK temp2; LINK head2; LINK cur;
    temp=head;
    temp2=head;
    while(fscanf(fp,"%s %s",head->eng,head->kor)==2)
    {
        head->next=malloc(sizeof(dictionary));
	head=head->next;
    }
    int node=nodeNum(temp);
    printf("%d\n\n",node);
    ptr=(LINK*)malloc(sizeof(LINK)*node);
    cur=temp2;
    for(int i=0;i<node;i++)
    {
	ptr[i]=cur;
	cur=cur->next;
    }
    for(int i=0;i<node;i++)
    {
	for(int j=i+1;j<node;j++)
	{
	    if(strcmp(ptr[i]->eng,ptr[j]->eng)>0)
	    {
		cur=ptr[i];
		ptr[i]=ptr[j];
		ptr[j]=cur;
	    }
	}
    }
    temp2=ptr[0];
    head2=temp2;
    cur=temp2;
    for(int i=1;i<node;i++)
    {
	cur->next=ptr[i];
	cur=cur->next;
    }
    cur->next=NULL;

    while(temp2!=NULL)
    {
	printf("%s %s\n",temp2->eng,temp2->kor);
	temp2=temp2->next;
    }
    while(1)
    {
       printf("1)영어 단어 맞추기\n2) 프로그램 종료\n");
       scanf("%d",&menu);
       switch(menu)
       {
	   case 1:
	       wordTest(head2,node);
	       break;
	   case 2:
	       system("clear");
	       exit(-1);
	       break;
	   default:
	       printf("메뉴를 다시 선택하세요\n");
	       break;
   	 }	
    }

    fclose(fp);
    return 0;
}
void wordTest(LINK head,int node)
{
    char temp[15];
    char tempK[30];
    char input[15];
    LINK cursor=head;
    double score=100.0/node;
    printf("score %f\n",score);
    double sum=0.0;
    while(cursor!=NULL)
    {
	printf("%s-> ",cursor->kor);
	scanf("%s",input);
	if(strcmp(input,".quit")==0)
	{
	    break;
	}
	if(strcmp(input,cursor->eng)==0)
	{
	    printf("correct!\n");
	    sum+=score;
	}
	else
	{
	    printf("incorrect!\n");
	}
	cursor=cursor->next;
    }
    printf("score: %f\n",sum);
}
int nodeNum(LINK head)
{
    int cnt=1;
    while(head->next->next!=NULL)
    {
	head=head->next;
	cnt++;
    }
    return cnt;
}




