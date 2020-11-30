#include<stdio.h>
#include<stdlib.h>
struct linked{
    char d;
    struct linked *next;
};
typedef struct linked ELEMENT;
typedef ELEMENT*LINK;

LINK string_to_list(char s[])
{
    int i=1;
    LINK head; LINK temp; LINK head2;
    head=malloc(sizeof(ELEMENT));
    head->d=s[0];
    head2=head;
    while(s[i]!='\0')
    {
	head->next=malloc(sizeof(ELEMENT));
	head=head->next;
	head->d=s[i];
	i++;
    }
    return head2;
}
void print(LINK head){
    if(head==NULL)
	printf("NULL\n");
    else{
	printf("%c --> ",head->d);
	print(head->next);
    }
}
int main()
{
    char input[100];
    LINK h;
    printf("type: ");
    scanf("%s",input);
    h=string_to_list(input);
    print(h);
    return 0;

}
