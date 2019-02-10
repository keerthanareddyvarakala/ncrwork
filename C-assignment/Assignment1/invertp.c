#include<stdio.h>
int main()
{
     int X,P,N,RESULT;
     int invert(int,int,int);
     printf("wnter x : \n");
     scanf("%d",&X);
     printf("enter position :\n");
     scanf("%d",&P);
     printf("enter n :\n");
     scanf("%d",&N);
     RESULT=invert(X,P,N);
     printf("\ninverted integer is \t%d",RESULT);
     getch();
}
 
int invert(int X,int P,int N)
{
     int I,Y,LIMIT,LEN,BIN[15];
     LEN=0;
     while(X>0)
     {
    BIN[LEN]=X%2;
    X=X/2;
    LEN++;
     };
 
     for(I=LEN-1;I>-1;I--)
     {
    printf("%d ",BIN[I]);
     }
     printf("\n");
     LIMIT=P+N;
     if(LIMIT < LEN)
     {
    for(I=P-1;I<P+N-1;I++)
    {
        if(BIN[I]==0)
            BIN[I]=1;
        else
            BIN[I]=0;
    }
     }
     else
     {
       printf("large values of p and n");
     }
 
     printf("inverted integer in binary form \t");
     for(I=LEN-1;I>-1;I--)
     {
      printf("%d ",BIN[I]);
     }
     Y=0;
     for(I=LEN-1;I>=0;I--)
     {
    Y=Y*2+BIN[I];
     }
     return Y;
}

