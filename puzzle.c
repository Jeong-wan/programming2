#include<stdio.h>
#include<termio.h>
#include<stdlib.h>
#include<time.h>
void printRandom(int puzzle[4][4]);
void print(int puzzle[4][4]);
void inputKey(int puzzle[4][4]);
int endGame(int puzzle[4][4]);
int col=3;int row=3;
    int puzzle[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
int getch(){
    int ch;
    struct termios buf;
    struct termios save;
    tcgetattr(0,&save);
    buf=save;
    buf.c_lflag &= ~(ICANON|ECHO);
    buf.c_cc[VMIN]=1;
    buf.c_cc[VTIME]=0;
    tcsetattr(0,TCSAFLUSH,&buf);
    ch=getchar();
    tcsetattr(0,TCSAFLUSH,&save);
    return ch;
}
int main(int argc, char**argv)
{
    srand((unsigned int)time(NULL));
    int menu=atoi(argv[1]);
    char key;
    switch(menu)
    {
	case 1:
	    system("clear");
	    print(puzzle);
	    break;
	case 2:
	    system("clear");
	    printRandom(puzzle);
	    while(1)
	    {
		print(puzzle);
		printf("\n\t\t\t\t\t\t\t\t\t\t\t\t [종료: 'esc']");
	        inputKey(puzzle);
		if(endGame(puzzle))
		{
		    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   축하합니다");
		    print(puzzle);
		    sleep(3);
		    exit(-1);
		}
	    }
	    break;
	default:
	    break;
    }
    return 0;
}
void inputKey(int puzzle[4][4])
{
    int key;
	key=(int)getch();
	if(key==27)
	{
	    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t종료합니다.\n");
	    exit(-1);
	}
    	switch(key)
   	 {
	     case 107:
                 if(row>0)
		 {
		     puzzle[row][col]=puzzle[row-1][col];
		     puzzle[row-1][col]=0;
		     row--;
		     system("clear");
		 }
		 else
		 {
		     system("clear");
		     printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t옮길  수 없습니다.\n");
		 }
                 break;
	     case 108:
		 if(col>0)
		 {
		     puzzle[row][col]=puzzle[row][col-1];
		     puzzle[row][col-1]=0;
		     col--;
		     system("clear");
		 }
		 else
		 {
		     system("clear");
		     printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t옮길  수 없습니다.\n");
		 }
	         break;
             case 105:
		 if(row<3)
		 {
		     puzzle[row][col]=puzzle[row+1][col];
		     puzzle[row+1][col]=0;
		     row++;
		     system("clear");
		 }
		 else
		 {
		     system("clear");
		     printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t옮길  수 없습니다.\n");
		 }
	         break;
	     case 106:
		 if(col<3)
		 {
		     puzzle[row][col]=puzzle[row][col+1];
		     puzzle[row][col+1]=0;
		     col++;
		     system("clear");
		 }
		 else
		 {
		     system("clear");
		     printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t옮길  수 없습니다.\n");
		 }
	         break;
	     case 72:
	     case 75:
	     case 77:
	     case 80:
		 break;
	     default:
		 system("clear");
		 printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t알맞은 키를 입력하세요\n");
		 break;
	 }
}
int endGame(int puzzle[4][4])
{
    int cnt=0;
    for(int i=0;i<4;i++)
    {
	for(int j=0;j<3;j++)
	{
	    if((puzzle[i][j]-puzzle[i][j+1])==-1)
		cnt++;
	}
    }
    if(cnt==11)
	return 1;
    return 0;
}
void printRandom(int puzzle[4][4])
{
    int temp;
    srand((unsigned int)time(NULL));
    int a;
    int b;
    for(int i=0;i<30;i++)
    {
	a=rand()%4;
	b=rand()%4;
	for(int j=0;j<4;j++)
	{
	    for(int k=0;k<4;k++)
	    {
		temp=puzzle[j][k];
		puzzle[j][k]=puzzle[a][b];
		puzzle[a][b]=temp;
	    }
	}
    }
    for(int i=0;i<4;i++)
    {
	for(int j=0;j<4;j++)
	{
	    if(puzzle[i][j]==0)
	    {
		puzzle[i][j]=puzzle[3][3];
		puzzle[3][3]=0;
		break;
	    }
	}
    }
  }
void print(int puzzle[4][4])
{
    
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t");
    for(int i=0;i<4;i++)
    {
	for(int j=0;j<4;j++)
	{
	    if(puzzle[i][j])
		printf("%4d",puzzle[i][j]);
	    else
		printf("    ");
	}
	printf("\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t");
    }
}

		
