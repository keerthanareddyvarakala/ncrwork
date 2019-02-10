#include <stdio.h>
#include <math.h>
long long HToB(int n);
int BToH(long long n);

int main()
{
    long long n;
		int dn;
    printf("Enter a binary number: ");
    scanf("%lld", &n);

	printf("Enter a hexadecimal number: ");
    scanf("%x", &dn);

    printf("%lld in binary = %x in hexadecimal\n", n, BToH(n));
    printf("%x in hexadecimal = %lld in binary\n", dn, HToB(dn));
 
}

long long HToB(int n)
{
    long long binary = 0;
    int rem, i = 1;
    int dec = 0, j = 0, rem2;
	while (n != 0)
	{
		rem = n % 10;
		n /= 10;
		dec += rem*pow(16, i);
		++i;
		printf("%d\n decimal value",dec);
		while (dec != 0)
		{
			rem2 = n % 2;
			dec /= 2;
			binary += rem2*j;
			j *= 10;
		}
	}
    return binary;
}

int BToH(long long n)
{
	int dec = 0, i = 0, rem,rem2;
			int hex = 0;
	while (n != 0)
	{
	
		rem = n % 10;
		n /= 10;
		dec += rem*pow(2, i);
		++i;

		while (dec != 0)
		{
			rem2 = n % 16;
			dec /= 16;
			hex += rem2*i;
			i *= 10;
		}
	}
	
    return hex;
}

