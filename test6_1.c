#include<stdio.h>
int crypting(int , int);
int main(int argc, char*argv[])
{
    int key;
    key=atoi(argv[1]);
    int c;
    while((c=getchar())!=EOF)
	putchar(crypting(c,key));
    
    return 0;
}
int crypting(int crypt,int key)
{
    return crypt ^ key;
}
