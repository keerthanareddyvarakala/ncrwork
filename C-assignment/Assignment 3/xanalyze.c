#include<stdio.h>
void main()
{
	int x[8] = { 10,20,30,40,50,60,70,80 };
	printf("%d", x);
	printf("\n%d", x + 2);
	printf("\n%d", *(x));
	printf("\n%d", (*x+2));
	printf("\n%d", *(x+2));

}

