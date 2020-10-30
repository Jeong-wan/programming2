#include<stdio.h>
void bitPrint(int a)
{
    int n=sizeof(int)*8;
    int mask=1<<31;
    for(int i=1;i<=32;i++)
    {
	putchar(((a&mask)==0)?'0':'1');
	a<<=1;
	if(i%8==0&& i<n)
	    putchar(' ');
    }
}
int main()
{
    int a;
    scanf("%d",&a);
    bitPrint(a);
    return 0;
}
