#include<stdio.h>
#define WON 0
#define DOLLAR 1
typedef union wonOrDollar{
     int won;
     double dollar;
}wd;
typedef struct product{
       char *pname;
      _Bool w_d;
       wd price;
}product;
int pBuy(product* p,int,int);
int main()
{
    int money,rate;
    const product list[6]={{"PMP",WON,{.won=600000}},{"MP3",WON,{.won=153000}},{"SmartPhone",DOLLAR,{.dollar=520.40}},{"TV",DOLLAR,{.dollar=430.20}},{"Navigator",WON,{.won=350000}},{"Laptop",DOLLAR,{.dollar=1950.00}}};
    printf("보유금액과 환율을 입력하세요.\n");
    printf("보유금액: ");
    scanf("%d",&money);
    printf("환율: ");
    scanf("%d",&rate);
    pBuy(list,money,rate);
    return 0;
}
int pBuy(product* p,int money,int rate)
{
    int chk=0;
    double changeD,changeW;
    changeD=money/rate;
    if(p==NULL)
    {
	printf("error: null pointer\n");
	return -1;
    }
    printf("구매 가능한 제품은 다음과 같습니다.\n");
    for(int i=0;i<6;i++)
    {
	if((p+i)->w_d==DOLLAR)
	{
	    changeW=(p+i)->price.dollar*rate;
	    if(changeD>=(p+i)->price.dollar)
	    {
		printf("%-20s %.0lf원\n",(p+i)->pname,changeW);
		chk=1;
	    }
	}
	else
	{
	    if(money>=(p+i)->price.won)
	    {
		printf("%-20s %d원\n",(p+i)->pname,(p+i)->price.won);
		chk=1;
	    }
	}
    }
    if(chk==0)
	printf("구매 가능한 제품이 없습니다.\n");
}

	


