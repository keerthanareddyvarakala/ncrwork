#include<stdio.h>
#include<string.h>
#include<ctype.h>

int replace(char *s)
{
	int i,count=0;
	for(i=0;s[i]!='\0';i++)
	{
		
		if(s[i]==' ')
		{
			s[i]='-';
			count++;
		}
	}
	printf("%s\n",s);
	printf("%d is the no. of - inserted",count);	
	return count;
	   	   
}



int main()
{
	char s[]="the cat sat on the bed";
	replace(s);
	
}

