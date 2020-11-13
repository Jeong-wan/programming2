#include<stdio.h>
int main()
{
    FILE *otp=fopen("myfile","w");
    fprintf(otp,"test");
   // fflush(otp);
    getchar();
    fclose(otp);
    getchar();
    return 0;
}
