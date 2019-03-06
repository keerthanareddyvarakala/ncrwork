#include <stdio.h>
#include <string.h>

int *strcate(char *dest, const char *source)
{
	if (*dest != '\0' && *source != '\0')
	{
		while (*dest != '\0')
		{
			dest++;
			while ((*dest = *source) != '\0')
			{
				dest++;
				++source;
			}
		}
		return 1;
	}
	else
		return 0;
}
int main()
{
	char *str1='\0', *str2='\0';
	int n=0;
	printf("enter the strings:\n");
	scanf_s("%s",str1);
	scanf_s("%s",str2);
	printf("the entered strings are\n");
	puts(str1);
	puts(str2);
	
	while (n <= 5)
	{
		printf("1.Length\n2.Copy\n3.Concatenate\n4.Comparison\n5.Reversal\n");
		scanf_s("%d", &n);
		switch (n)
		{

		case 3:
			strcate(str1, str2);
			printf("the concatenated string is = %s\n", str1);
			break;

		}
		getchar();
	}
}
