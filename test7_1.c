#include<stdio.h>
float tri(float w, float h){return w*h/2;}
#define TRI(w,h) ((w)*(h)/2)
int main(){
    float  a;
    a=tri(1,1);
    printf("area is %f\n",a);
    a=TRI(5,5);
    printf("area is %f\n",a);
    return 0;
}
