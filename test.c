#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *a[3][2]={"abc","defg","hi","jklmno","pqrstuvw","xyz"};
    printf("%c %c %s %s \n",***a+2,*(*(*(a+1)+1)+2),**(a+2),*(*(a+1)+1)+2);
	


    return 0;

}

