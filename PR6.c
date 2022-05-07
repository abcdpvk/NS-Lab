//Practical 6 : RSA Algorithm
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int p, q;
    int n, fi_n;

    int data, cipher, decrypt;

    while (1) {
        printf("Enter Two Prime No. P and Q :: \n\n");
        scanf("%d %d", & p, & q);

        if (!(isPrime(p) && isPrime(q)))
            printf("\nKindly enter Prime Numbers Only...\n");

        else
            break;
    }

    n = p * q;
    fi_n = (p - 1) * (q - 1);

    int e = 7;
    int count = 0;

    while (e < fi_n) {
        count = gcd_Find(e, fi_n);
        if (count == 1)
            break;
        else
            e++;
    }

    int d = 0;

    for (d = e + 1; d <= 100; d++) {
        if (((d * e) % fi_n) == 1)
            break;
    }

    printf("\nHence, \n\ne :: %d\nd :: %d\nfi_n :%d\n", e, d, fi_n);

    printf("Message to be Encrypted :: ");
    scanf("%d", & data);

    cipher = power_Mod(data, e, n); // M^e modp
    printf("Cipher Text :: %d\n", cipher);

    decrypt = power_Mod(cipher, d, n);//C^d mod P
    printf("Decrypted Text :: %d\n", decrypt);
    return 0;
}


int gcd_Find(int n1, int n2) {
    int temp;
    while (1) {
        temp = n1 % n2;
        if (temp == 0)
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


int power_Mod(int a, int b, int n) {
    long long x = 1, y = a;

    while (b > 0) {
        if (b % 2 == 1)
            x = (x * y) % n;
        y = (y * y) % n; // Squaring the base
        b /= 2;
    }
    return fmod(x, n);
}
