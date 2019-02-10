#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
	char s[20],ch,temp;
	int i;
	printf("enter the string and the character\n");
	gets(s);
	scanf("%c",&ch);
	
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]==ch)
			s[i]='*';
			
	}

	printf("%s\n",s);
	
		
	
	
}	 

