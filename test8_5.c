#include<stdio.h>
int main()
{
    char a=0xff;
    short b=0xffff;
    int c=0xffffffff;
    long d=0xffffffffff;
    printf("%#hhx %#hx %#x %#lx\n",a,b,c,d);
    return 0;
}
