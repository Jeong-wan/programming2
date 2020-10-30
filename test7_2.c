#include<stdio.h>
#define PRN_3(x,y,z) printf(#x": %.1f, ",x); printf(#y": %.1f, ",y); printf(#z": %.1f\n",z)
int main()
{
    float x=1.1,y=2.2,z=3.3;
    PRN_3(x,y,z);
    return 0;
}
