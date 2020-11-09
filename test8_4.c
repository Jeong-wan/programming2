#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char booklist[5][50]={"Cygwin과 함께 배우는 C 프로그래밍","C 99","A book on C","C 프로그래밍","자바 프로그래밍"};
    char a[100];char *ptr; int i=0;
    int chk=0;
    printf("검색 문장을 입력하세요 : ");
    scanf("%s",a);
    getchar();
    for(int i=0;i<5;i++)
    {
	ptr=strstr(*(booklist+i),a);
	if(ptr==NULL)
	    continue;
	else
	    printf("%s\n",booklist[i]);
    }

    return 0;
}

