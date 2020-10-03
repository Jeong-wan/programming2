#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compare(void *a,void *b);
int main()
{
    char *word[10];
    char buf[10];
    for(int i=0;i<10;i++)
    {
	word[i]=(char*)malloc(sizeof(char)*10);
	printf("단어를 입력하세요: ");
	memset(buf,(char)0xff,sizeof(buf));
	scanf("%s",buf);
	strcpy(word[i],buf);
    }
    printf("=====정렬 전 문자=====\n");
    for(int i=0;i<10;i++)
	printf("%s\n",word[i]);
    qsort(word,10,sizeof(char*),compare);
    printf("=====정렬 후 문자=====\n");
    for(int i=0;i<10;i++)
	printf("%s\n",word[i]);

    for(int i=0;i<10;i++)
	free(word[i]);
}
int compare(void *a,void *b)
{
    return strcmp(*(char**)a,*(char**)b);
}


