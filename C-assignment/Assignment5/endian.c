#include <stdio.h> 
int main()
{
	unsigned int i = 300;
	char *c = (char*)&i;
	if (*c)
		printf("Little endian");
	else
		printf("Big endian");
	getchar();
	return 0;
}