#include<stdio.h>
#include<termio.h>
int getch(void)
{
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
    int set;
    system("ls");
    printf("몇 초 후에 화면을 지울까요? : ");
    set=getch()-'0';
    printf("%d\n",set);
    sleep(set);
    system("clear");
    return 0;
}

