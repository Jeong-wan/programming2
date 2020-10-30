#include<stdio.h>
int main()
{
    char a[10]="Hello";
    char *p=a;
    printf("%p\n",p);
    printf("%c\n",p);
    printf("%d\n",p);
    printf("&a=%p,&p=%p,p=%p\n",&a,&p,p);
    return 0;
}
