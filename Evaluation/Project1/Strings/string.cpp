#include <stdio.h>
#include <string.h>
#include<stdlib.h>


char *strcpyy(char *s1, const char *s2)
{
	char *dst = s1;
	const char *src = s2;
	while ((*dst++ = *src++) != '\0')
		;               
	return s1;
}
char *strcate(char *s1, const char *s2)
{
	char *s = s1;
	while (*s != '\0')
		s++;
	strcpyy(s, s2);
	return s1;
}
int strlength(const char *s)
{
	const char *p = s;
	while (*p != '\0')
		p++;
	return (p - s);
}
int strcmpa(const char *s1, const char *s2)
{
	unsigned char uc1, uc2;
	while (*s1 != '\0' && *s1 == *s2) {
		s1++;
		s2++;
	}
	uc1 = (*(unsigned char *)s1);
	uc2 = (*(unsigned char *)s2);
	return ((uc1 < uc2) ? -1 : (uc1 > uc2));
}
char *strrevv(char *str)
{
	char *p1, *p2,temp;
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
	{
		temp= *p1;
		*p1 = *p2;
		*p2 = temp;
	}
	return str;
}

int main()
{
	int n=0, res;
	char copy[50] = "";
	char *temp;
	char *str1;
	str1 = NULL;
	str1 = (char*)malloc(50 * sizeof(char));
	char *str2;
	str2 = NULL;
	str2 = (char*)malloc(50 * sizeof(char));
	printf("Enter two strings:");
	gets_s(str1, 29);
	gets_s(str2, 19);
	temp = str1;
	while (n <= 5)
	{
		printf("1.Length\n2.Copy\n3.Concatenate\n4.Comparison\n5.Reversal\n");
		scanf_s("%d", &n);
		int res;
		switch (n)
		{
			
			case 1:
				printf("length of first string is %d\n", strlength(str1));
				printf("length of second string is %d\n", strlength(str2));
				break;
			case 2:
				strcpyy(copy, str2);
				printf("The string is copied  %s,%s\n", copy,str2);
				break;
			case 3:
				strcate(str1, str2);
				printf("the concatenated string is = %s\n", str1);
				break;
			case 4:
				res=strcmpa(str1, str2);
				if (res <= -1)
				{
					printf("first string is lexographically less than the second\n");
				}
				else if (res >= 1)
				{
					printf("second string is lexographically less than the first\n");
				}
				else if (res == 0)
				{
					printf("equal\n");
				}

				break;
			case 5:
				printf("reversal of first string is %s\n", strrevv(str1));
			
				break;

		}
		getchar();
	}
}
