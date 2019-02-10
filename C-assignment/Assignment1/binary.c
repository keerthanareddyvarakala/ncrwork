#include <stdio.h>
int main()
{
int a;
int x0,x1,x2,x3,x4;
x0=0,x1=0,x2=0,x3=0,x4=0;
printf("Enter number ");
scanf("%d",&a);
if(a< 1 || a > 31)
{
printf("Entered number is out of range\n");
return 0;
}
printf("Binary equivalent of %d is ",a);
x0 = a%2;
a = a/2;
if(a!=0)
{
x1 = a%2;
a = a/2;
}
else
{
printf("%d\n",x0);
return 0;
}
if(a!=0)
{
x2 = a%2;
a = a/2;
}
else
{
printf("%d%d\n",x1,x0);
return 0;
}
if(a!=0)
{
x3 = a%2;
a = a/2;
}
else
{
printf("%d%d%d\n",x2,x1,x0);
return 0;
}
if(a!=0)
{
x4 = a%2;
a = a/2;
}
else
{
printf("%d%d%d%d\n",x3,x2,x1,x0);
return 0;
}
printf("%d%d%d%d%d\n",x4,x3,x2,x1,x0);
return 0;
}

