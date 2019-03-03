#include<stdio.h>
struct time
{
	int hr;
	int min;
	int sec;
};
void main()
{
	struct time t;
	printf("enter hr min and sec of the day");
	scanf("%d %d %d", &t.hr, &t.min, &t.sec);
	printf("\n%d:%d:%d", t.hr, t.min, t.sec);

}