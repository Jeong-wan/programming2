#include<stdio.h>
#include<stdlib.h>
int main()
{
    int aa=10;
    int *p=&aa;
    printf("p=%u,&aa=%u,&p=%u\n\n",p,&aa,&p);
    char *a[2][3]={"abc","defg","hi","jklmno","pqrstuvw","xyz"};
    char *b[5]={"10","40","30","30","5"};
    printf("%c %s\n\n",b[1],b[1]);
    printf(" %c\n",(*(*(a+1)+1))[3]);
    printf(" %s\n",a[0][0]+1);
    printf("sizeof a =%d\n",sizeof(a));
    if(sizeof(a[0][0])==sizeof(*a[0][0]))
	    printf("they are same\n");
    printf("sizeof(a[0][0])=%d\n",sizeof(a[0][0]));
    printf("sizeof(*a[0][0])=%d\n",sizeof(*a[0][0]));
	


    return 0;

}

