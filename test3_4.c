#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *word[10]; char buf[20];
    printf("단어를 입력하세요\n");
    for(int i=0;i<10;i++)
    {
        word[i]=(char*)malloc(sizeof(char)*strlen(buf));
//	memset(buf,(char)0xff,strlen(buf));
	scanf("%s",word[i]);
//	strcpy(word[i],buf);
    }
    printf("입력한 단어를 표시합니다.\n");
    printf("=========================\n");
    for(int i=0;i<10;i++)
	printf("%s\n",*(word+i));
    for(int i=0;i<10;i++)
	free(word[i]);
    return 0;
}

