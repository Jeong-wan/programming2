#include<stdio.h>
#include<stdarg.h>
#include<string.h>
#include<stdlib.h>
void myprintf(char *format,...);
int main()
{
    myprintf("gender: %c,age: %d \n",'M',20);
    return 0;
}
void myprintf(char *format,...)
{
    va_list ap;
    char ptr;
    char *temp=malloc(sizeof(char)*50);
    va_start(ap,format);
    while(*format)
    {
	ptr=*format++;
	if(ptr=='%')
	{
	    ptr=*format++;
	    if(ptr=='c')
		sprintf(temp,"%s%c",temp,va_arg(ap,int));
	    else if(ptr=='d')
		sprintf(temp,"%s%d",temp,va_arg(ap,int));
	}
	else
	    sprintf(temp,"%s%c",temp,ptr);
    }

    va_end(ap);
    while(*temp)
    {
	putchar(*temp++);
    }
}
