//Practical 8 Elgamal
#include<stdio.h>
#include<conio.h>

void main()
{

    int p,al,z,be,k,gcd,r,s,m,hashv,inv,rem,v1,v2;



    abc:
        printf("\nEnter Value of P :: ");
        scanf("%d",&p);
        if(isPrime(p)==0)
        {
             printf("\nUghhh.....P should be Prime!!!");
            goto abc;
        }

    printf("Primitive root of alpha :: ");
    scanf("%d",&al);

    printf("Enter the Value of secret value Z (between 1 to p-1) :: "); // pvt key
    scanf("%d",&z);

    while(z<1||z>p-1)
    {
            printf("z should be between 1 to p-1 enter again :: ");
            scanf("%d",&z);
    }


    //beta
    be=powMod(al,z,p);// al^z mod p

    printf("Beta Value :: %d\n",be);


    printf("Enter the value of K:");//
    scanf("%d",&k);
    gcd=findGCD(k,p-1);
    if(gcd==1)
    {
        r=powMod(al,k,p);
    }

    printf("Value of R :: %d\n\n",r);
    printf("Enter Hash value m :: ");
    scanf("%d",&m);
    hashv=m-z*r;



    int x=0;

    while(1)
    {

        inv=k*x;
        rem=inv%(p-1);

        if(rem==1)
        {
            inv=x;
            break;

        }
        inv=0;
        x++;

    }


    s=((inv%(p-1)*(hashv%(p-1)))%(p-1));

    if(s<0)
    {
        s=(p-1)+s;
    }

    printf("\nS Value :: %d\n\n",s);



    v1=powMod(al,m,p);// Aplha ^ m mod p
    v2=(powMod(be,r,p)*powMod(r,s,p)%p);// be ^ r . r^s mod p

    printf("V1 :: %d",v1);
    printf("\n\nV2 :: %d",v2);
    if(v1==v2)
    {

        printf("\n\nSignature Verified!!!\n\n");

    }
    else
    {

        printf("\n\nSignature Not Verified!!!\n\n");
    }
}

int powMod(int a, int b, int n)
{
    long long x = 1, y = a;

    while (b > 0)
    {
        if (b % 2 == 1)
            x = (x * y) % n;
        y = (y * y) % n; // Squaring the base
        b /= 2;
    }
    return fmod(x,n);
}

int findGCD(int n1, int n2)
{
    int temp;
    while(1)
    {
        temp = n1%n2;
        if(temp==0)
        return n2;
        n1 = n2;
        n2 = temp;
    }
}

int isPrime(int n)
{

    if (n <= 1)
        return 0;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return 0;

    return 1;
}
//19 10 16 5 14
