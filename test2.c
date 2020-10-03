#include<stdio.h>
void func(int a, int b,int c[]);
int main()
{
    int dividend,divisor;
    int result[2];
    printf("피제수를 입력하세요 : ");
    scanf("%d",&dividend);
    printf("제수를 입력하세요 : ");
    scanf("%d",&divisor);
    func(dividend,divisor,result);
    printf("몫: %d 나머지: %d\n",result[0],result[1]);
}
void func(int a,int b,int c[])
{
    c[0]=a/b;
    c[1]=a%b;
}
