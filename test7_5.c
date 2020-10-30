#include<stdio.h>
#include<termio.h>
int getch(void){
    int ch;
    struct termios buf;
    struct termios save;
    tcgetattr(0,&save);
    buf=save;
    buf.c_lflag &= ~(ICANON | ECHO);
    buf.c_cc[VMIN]=1;
    buf.c_cc[VTIME]=0;
    tcsetattr(0,TCSAFLUSH,&buf);
    ch=getchar();
    tcsetattr(0,TCSAFLUSH,&save);
    return ch;
}
int main()
{
    char a='a';
    int ch;
    printf("%c\n",a);
    ch=getch();
    if(ch=='a')
    {
	printf("%c\n",ch);
	printf("Good\n");
    }
    else
    {
	printf("%c\n",ch);
	printf("Bad\n");
    }
    return 0;
}


