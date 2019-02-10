#include<stdio.h> 

int sum(int arr[], int n, int s) 
{ 
    int arr_s, i, j; 
  
     
    for (i = 0; i < n; i++) 
    { 
        arr_s = arr[i]; 
  
        
        for (j = i+1; j <= n; j++) 
        { 
            if (arr_s == s) 
            { 
                printf ("Sum found between indexes %d and %d", i, j-1); 
                return 1; 
            } 
            if (arr_s > s || j == n) 
                break; 
           arr_s = arr_s + arr[j]; 
        } 
    } 
  
    printf("No subarray found"); 
    return 0; 
} 
  
int main() 
{ 
    int *arr;
	int len=1,s,n,i;
	n = sizeof(arr)/sizeof(arr[0]);
	printf("enter array elements"); 
		for(i=1;i<=100;i++)
		{
			scanf("%d",&arr[i]);
			if(arr[i]<0)
				break;
			else
				len++;	     	 	 	 
		}
		for(i=1;i<=len;i++)
		{
			printf("%d\t",arr[i]);
		}
	printf("enter sum");
	scanf("%d",&s);
    sum(arr, n, s); 
    return 0; 
} 

