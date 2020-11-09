#include<stdio.h>
#define PI 3.14
#define AREA(r) ((r)*(r)*PI)
float area_f(float r) {return r*r*PI;}
int main()
{
    float a;
    int i=0;
    printf("macro \n\n");
    while(++i<=10){
	printf("%d\t",i);
	a=AREA(i);
	printf("%.2f\n",a); 	
    }
    i=1;
    printf("func\n\n");
    while(i<=10)
    {
	printf("%d\t",i);
	a=area_f(i++);
	printf("%.2f\n",a);
    }
    return 0;
}

