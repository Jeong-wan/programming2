#include<stdio.h>
#include<math.h>
void func_addr(void *f);
int main()
{
    func_addr(cos);
    func_addr(main);
    return 0;
}
void func_addr(void *f)
{
    if(f==cos)
	printf("cos address : %p\n",f);
    else
	printf("address: %p\n",f);
}
