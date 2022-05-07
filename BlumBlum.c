#include<stdio.h>

int p,q,n,x0,seed;

int main()
{
    int num;
    printf("***********Blum Blum Shub Pseudo-Random Number Generator*************\n");
    printf("\nEnter p and q such that they are large primes...\n\n");
    printf("Enter Value for p :: ");
    scanf("%d",&p);

    printf("Enter Value for q :: ");
    scanf("%d",&q);
     n=p*q;
     printf("\nn = p*q, Hence n= %d * %d = %d",p,q,n);
    printf("\n\nEnter Value for x0 \(seed value\) such that gcd\(x0,p*q\) = 1 :: ");
    scanf("%d",&seed);

    printf("Count of Numbers ::  ");
    scanf("%d",&num);
    x0=seed;

    printf("\nRandom Numbers :: ");
    for (int i=0; i<num; i++)
    {

        printf("%d \t",Rand());
    }
    printf("\nIn Form of Bits:: ");
    for (int i=0; i<num; i++)
    {
        printf("%d \t",RandomBit());
    }
    printf("\n\n");
    return 0;
}
int Rand()
{
	int nextRandNum = (x0 * x0) % n;
	x0 = nextRandNum;
	return nextRandNum;
}
int RandomBit()
{
	return Rand() % 2;
}
