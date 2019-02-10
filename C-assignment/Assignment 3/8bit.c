#include<stdio.h>
int DToB(int n);

int main()
{
	 int dn;
	  printf("Enter a decimal number: ");
    scanf("%d", &dn);
	printf("no of ones is %d", DToB(dn));
}
int DToB(int n)
{
    long long binary = 0;
    int rem, i = 1;
	int count=0;

    while (n!=0)
    {
        rem = n%2;
		if(rem==1)
			count=count+1;
        n /= 2;
        binary += rem*i;
        i *= 10;
    }
    return count;
}
