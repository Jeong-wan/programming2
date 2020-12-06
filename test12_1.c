#include<stdio.h>
#include<stdarg.h>
#define END 0
#define INT 1
#define DOUBLE 2

int add(int,...);
int main()
{
    printf("sum=%d\n",add(3,4,5,6));
    printf("sum=%d\n",add(4,6,2,4,8));
    return 0;
}
int add(int num,...)
{
    int sum=0;
    va_list ap;
    va_start(ap,num);
    while(num!=0)
    {
	sum+=va_arg(ap,int);
	num--;
    }
    va_end(ap);
    return sum;

}
