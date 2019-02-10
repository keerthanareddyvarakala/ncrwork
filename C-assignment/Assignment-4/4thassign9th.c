#include<stdio.h>
int main()
{
	char s1[10], s2[10];
	int i,j;
	printf("enter two strings");
	scanf("%s", s1);
	scanf("%s", s2);
	for (i = 0; i < strlen(s1); i++)
	{
		for (j = 0; j < strlen(s2); j++)
		{
			if (s1[i] == s2[j])
			{
				printf("match found at %d", i+1);
				return;
			}
		}
	}
	return 0;
}

