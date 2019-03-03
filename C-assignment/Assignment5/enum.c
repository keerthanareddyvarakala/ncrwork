#include<stdio.h>

enum operations
{
	addition,
	multiplication,
	substraction
};
void main()
{
	enum operation o;
	int real, img, r1, r2, i1, i2;
	printf("enter the real and img part of first complex number ");
	scanf("%d %d", &r1, &i1);
	printf("\nenter the real and img part of second complex number ");
	scanf("%d %d", &r2, &i2);
	printf("\nenter the operation");
	scanf("%d", &o);
	switch (o)
	{
	case addition:
		real = r1 + r2;
		img = i1 + i2;;
		break;
	case multiplication:
		real = r1*r2 - i1*i2;
		img = r1*i2 + r2*i1;
		break;
	case substraction:
		real = r1 - r2;
		img = i1 - i2;
		break;
	default:
		printf("ënter a valid operation");
		break;
	}
	printf("%d + %d i", real, img);
}