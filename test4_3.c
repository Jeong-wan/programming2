#include<stdio.h>
#include<time.h>
int main()
{
    struct tm *t;
    time_t now;
    now=time(NULL);
    t=localtime(&now);
    int day=t->tm_wday;
    char *when; char *time;
    switch(day){
	case 0:
	    when="일";
	    break;
	case 1:
	    when="월";
	    break;
	case 2:
	    when="화";
	    break;
	case 3:
	    when="수";
	    break;
	case 4:
	    when="목";
	    break;
	case 5:
	    when="금";
	    break;
	case 6:
	    when="토";
	    break;
	default:
	    break;
    }
    if(t->tm_hour>=11)
	time="오후";
    else
	time="오전";


    printf("오늘은 %d년 %d월 %d일 %s요일 입니다\n",t->tm_year+1900,t->tm_mon+1,t->tm_mday,when);
    printf("현재 시간은 %s %d시 %d분 %d초 입니다\n",time,t->tm_hour,t->tm_min,t->tm_sec);
    return 0;
}
