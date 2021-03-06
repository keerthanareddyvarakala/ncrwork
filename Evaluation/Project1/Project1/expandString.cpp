#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 100
void getString(char s[], int maxlimit);
void expand(char s1[], char s2[]);

int main(void)
{
	char s1[MAXLINE], s2[MAXLINE];

	getString(s1, MAXLINE);

	expand(s1, s2);

	printf("%s", s2);
	getchar();

	return 0;
}

void getString(char s[], int lim)
{
	int i, c;
	printf("enter the string\n");
	for (i = 0; i<lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';
}

void expand(char s1[], char s2[])
{
	int i, j, c;

	i = j = 0;

	while ((c = s1[i++]) != '\0')
		if (s1[i] == '-')
		{
			if (s1[i + 1] == '-')
			{
				printf("Incorrect input");
				exit(0);
			}
			else if(s1[i + 1] >= c)
				i++;
			i++;
			while (c < s1[i])
				s2[j++] = c++;

		}

		else
			s2[j++] = c;

	s2[j] = '\0';
}

