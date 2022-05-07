//Defie Hellman
#include<stdio.h>
int isPrime(int n)
{

    if (n <= 1)
        return 0;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return 0;

    return 1;
}
int main()
{
    int p;
    int alpha;

    int xA,xB;//Pri keys
    int yA,yB;//Pub key
    int A,B;// secret keys

    while(1)
    {
       abc:
           printf("\nEnter value for P :: ");
        scanf("%d",&p);
        if(isPrime(p)==0)
        {
             printf("\nUghhh.....P should be Prime!!!");
            goto abc;
        }


        printf("\nEnter Primitive Root of p :: ");
        scanf("%d",&alpha);

        printf("\nEnter xA :: ");
        scanf("%d",&xA);

        printf("\nEnter xB :: ");
        scanf("%d",&xB);

        if(xA < p && xB < p)
        {
            yA=powMod(alpha,xA,p);
            yB=powMod(alpha,xB,p);
            A=powMod(yB,xA,p);
            B=powMod(yA,xB,p);
            printf("\nSecret Key for A :: %d\n",A);
            printf("Secret Key for B :: %d",B);
            printf("\n----------------------\n");
            return 0;
        }
        else
        {
            printf("xA and xB should be < than prime number !!!!");
        }
    }

    return 0;
}
int powMod(int a, int b, int n)
{
    long long x = 1, y = a;

    while (b > 0)
    {
        if (b % 2 == 1)
            x = (x * y) % n;
        y = (y * y) % n;
        b /= 2;
    }
    return fmod(x,n);
}
//inp 11 5 6 7 O/p 3
