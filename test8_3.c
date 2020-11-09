#include<stdio.h>
void mygets(char *);
int main()
{
    char input[100];
    printf("문자열을 입력하세요 : ");
    mygets(input);
    printf("입력 문자열 : ");
    printf("%s",input);
    printf("입력 끝");
    return 0;
}
void mygets(char *input)
{
    int i=0;
    int a;
    while(1)
    {
	a=getchar();
	if(a=='\n')
	    break;
	input[i]=a;
	i++;
    }
}
