#include<stdio.h>
#include<string.h>
#include<ctype.h>

void reverse(char *arr,int begin,int end)
{
	char temp;
	if(begin>=end)
	{
		printf("the string is %s\n",arr);
		return;
	}
	else
	{
		temp=arr[begin];
		arr[begin]=arr[end];
		arr[end]=temp;
		begin++;
		end--;
		reverse(arr,begin,end);
	
	}
	
}

int main()
{
	char s[20];
	printf("enter string\n");
	scanf("%s",s);
	reverse(s,0,strlen(s)-1);
}

