#include<stdio.h>
struct Structure
{
	int a;
	char s;
};
union Union
{
	int a;
	char s;
};
void main()
{
	struct Structure s;
	union Union u;
	printf("size of structure is %d\n", sizeof(s));
	printf("size of union is %d", sizeof(u));

}