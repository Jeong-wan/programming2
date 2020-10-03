#include<stdio.h>
int main(int argc, char **argv)
{
    int i=atoi(argv[1]);
    int j=atoi(argv[2]);
    int k=atoi(argv[3]);
    printf("평균은 %d 입니다\n",(i+j+k)/3);
    return 0;


}

