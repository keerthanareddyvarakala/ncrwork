 
#include <stdio.h>
#include <math.h>  

int rearrange(int arr[], int n) 
{ 
    int key, j , i; 
    for( i = 1; i < n; i++) 
    { 
        key = arr[i]; 
  
        
        if (key > 0) 
            continue; 
  
       
        j = i - 1; 
        while (j >= 0 && arr[j] > 0) 
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
  
       
        arr[j + 1] = key; 
    } 
} 
  

void printArray(int arr[], int n) 
{ 
	int i;
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
} 
  

int main() 
{ 
    int arr[10];
	int n,i;
	n = sizeof(arr)/sizeof(arr[0]);
	printf("enter 10 array elements"); 
		for(i=1;i<=10;i++)
		{
			scanf("%d",&arr[i]);
					
		}
    rearrange(arr, n); 
    printArray(arr, n); 
    return 0; 
} 

