#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char *text;
    
  	 n=10;
   
    text=(char*)malloc(n*sizeof(char));
    
    printf("Enter text: ");
    scanf(" ");
    gets(text);
    
    printf("Inputted text is: %s\n",text);

    free(text);
    
    return 0;
}

