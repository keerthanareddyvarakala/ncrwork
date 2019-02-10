#include<stdio.h>
#include<string.h>
int main()
{
    char str[20];
    int i;
    printf("Enter String without spaces in between them: ");
    scanf("%s",str);
    for(i=0;i<=strlen(str);i++)
    {
        if(str[i]>=65 && str[i]<=90)
        str[i]=str[i]+32;
    }
    printf("String in Lowercase: %s",str);
    for(i=0;i<=strlen(str);i++)
    {
        if(str[i]>=97 && str[i]<=122)
            str[i]=str[i]-32;
    }
    printf("\n\nString in Uppercase: %s",str);
    return 0;
}

