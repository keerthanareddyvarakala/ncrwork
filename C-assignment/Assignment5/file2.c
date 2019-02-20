#include <stdio.h> 
#include <stdlib.h> 
  
int main(int argc,char *argv[]) 
{ 
    FILE *fptr,*fp; 
  
    char filename[100],file2[100], c,ch;  
  printf("Enter the filename to open and other file \n"); 
    scanf("%s", filename);
	  scanf("%s", file2);
  
    
    fptr = fopen(filename, "r"); 
	fp = fopen(file2, "w+"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
   
    c = fgetc(fptr); 
    while (c != EOF)
	 
    {
		 printf ("%c", c);  
        c = fgetc(fptr);
		ch = (unsigned char)(~c);
		 printf ("%u", ch);
		fputc(ch,fp); 
    } 
	printf("\n");

    fclose(fptr);
	fclose(fp); 
    return 0; 
}

