#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>  
int main() 
{ 
    FILE *fptr; 
  
    char filename[100], c[200]; 
	int i;
  
    printf("Enter the filename to open \n"); 
    scanf("%s", filename); 
  
    
    fptr = fopen(filename, "a+"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
	printf("enter the string");
	scanf("%s",c);
	 
	for(i=0;i<strlen(c);i++)
	{
		if (c[i] >= 65 && c[i] <= 90)
		
			fputc(tolower(c[i]),fptr);
		
			
		else if (c[i] >= 97 && c[i] <= 122)
			fputc(toupper(c[i]),fptr);	  
   
  } 
    fclose(fptr); 
    return 0; 
}

