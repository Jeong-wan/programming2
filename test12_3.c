#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
//#define SIG_DFL ((void(*)(int))0)
void sigfunc(int sig){
    printf("%d번 신호가 발생했습니다.\n",sig);
    exit(-1);
}
int main()
{
    int i,j;
    signal(SIGFPE,sigfunc);
    scanf("%d",&j);
    i=7/j;
    printf("%d",i);
    return 0;
}
