#include<stdio.h>
#include<string.h>

int s_matrix0[4][4] = { {1,0,3,2},
						{3,2,1,0},
						{0,2,1,3},
						{3,1,3,2} };

int s_matrix1[4][4] = { {0,1,2,3},
						{2,0,1,3},
						{3,0,1,0},
						{2,1,0,3} };

int s0=0, s1=0;
int row=0, col=0;
int s0_binary[2], s1_binary[2];
int result[2];

int to_digit(int a, int b)
{
    int output;
    if(a==1 && b==1)
        output = 3;

    if(a==0 && b==1)
        output = 1;

    if(a==1 && b==0)
        output = 2;

    if(a==0 && b==0)
        output = 0;

    return output;
}

void to_binary(int num)
{
    int x;

    if(num == 3)
    {
        for(x=0; x<2; x++)
            result[x] = 1;
    }
    else if(num == 1)
    {
        result[0] = 0;
        result[1] = 1;
    }
    else if(num == 2)
    {
        result[0] = 1;
        result[1] = 0;
    }
    else if(num == 0)
    {
        for(x=0; x<2; x++)
            result[x] = 0;
    }
}

void main()
{
    int i,j,index;

    int k1[8], k2[8];
    int afterp10[11], ls1[10], ls2[10], afterip[8], afterep[8], afterp4[4];
    int aftersboxesone[4], aftersboxestwo[4];
    int leftafterip[4], rightafterip[4];
    int leftafterep[4], rightafterep[4];
    int leftafterone[4], rightafterone[4];
    int afteripinverse[8];
    int afterone[8], aftertwo[8];

    int p10[10] = {3,5,2,7,4,10,1,9,8,6};
    int p8[8] = {6,3,7,4,8,5,10,9};

    int ip[8] = {2,6,3,1,4,8,5,7};
    int ep[8] = {4,1,2,3,2,3,4,1};
    int p4[4] = {2,4,3,1};
    int ipinverse[8] = {4,1,3,5,7,2,8,6};

    int key[11] = {1,0,1,0,0,0,0,0,1,0};
    int plain[8] = {0,1,1,0,1,1,0,1};

    printf("Practical 4 Simplified DES.\n");

    printf("\nPart 1----------------KEY GENERATION----------------\n");
    printf("\n10 Bit Key :: ");
    for(i=0; i<10; i++)
        printf("%d ",key[i]);

    printf("\nP10 Permutation pattern :: ");
    for(i=0; i<=9; i++)
        printf("%d ",p10[i]);

    for(i=0; i<=9; i++)
    {
        index = p10[i];
        afterp10[i] = key[index - 1];
    }
    afterp10[i] = '\0';

    printf("\n\nAfter applying P10 Permutation, we have :: ");
    for(i=0; i<=9; i++)
        printf("%d ",afterp10[i]--);

    for(i=0; i<5; i++)
    {
        if(i == 4)
            ls1[i]=afterp10[0];
        else
            ls1[i]=afterp10[i+1];
    }

    for(i=5; i<10; i++)
    {
        if(i == 9)
            ls1[i]=afterp10[5];
        else
            ls1[i]=afterp10[i+1];
    }

    printf("\n\nAfter applying LS-1 :: ");
    for(i=0; i<10; i++)
        printf("%d ", ls1[i]);

    printf("\n\nP8 Permutation Pattern ::  ");
    for(i=0;i<8;i++)
        printf("%d ",p8[i]);

    index=0;
    for(i=0; i<=9; i++)
    {
        index = p8[i];
        k1[i] = ls1[index - 1];
    }

    printf("\n\nGenerated Key 1 is :: ");
    for(i=0;i<8;i++)
        printf("%d ",k1[i]);

    for(i=0; i<3; i++)
    {
        ls2[i]=ls1[i+2];
    }
    ls2[3]=ls1[0];
    ls2[4]=ls1[1];

    for(i=5; i<8; i++)
    {
        ls2[i]=ls1[i+2];
    }
    ls2[8]=ls1[5];
    ls2[9]=ls1[6];

    printf("\n\nAfter applying LS-2 :: ");
    for(i=0; i<10; i++)
        printf("%d ", ls2[i]);

    printf("\nP8 Permutation Pattern ::  ");
    for(i=0;i<8;i++)
        printf("%d ",p8[i]);

    index=0;
    for(i=0; i<=9; i++)
    {
        index = p8[i];
        k2[i] = ls2[index - 1];
    }

    printf("\n\nWe have Key 2 as ::  ");
    for(i=0;i<8;i++)
        printf("%d ",k2[i]);

    printf("\n\nPART 2----------------S-DES ENCRYPTION----------------");
    printf("\n\nPlain Text is :: ");
    for(i=0; i<8; i++)
        printf("%d ",plain[i]);


    printf("\nInitial Permutation (IP) is :: ");
    for(i=0; i<8; i++)
        printf("%d ",ip[i]);

    for(i=0; i<8; i++)
    {
        index = ip[i];
        afterip[i] = plain[index - 1];
    }
    afterip[i] = '\0';

    printf("\nAfter applying Initial Permutation :: ");
    for(i=0; i<8; i++)
        printf("%d ", afterip[i]);

    printf("\n\nExpand Permutation :: ");
    for(i=0; i<8; i++)
        printf("%d ",ep[i]);

    for(j=0; j<4; j++)
        leftafterip[j] = afterip[j];

    for(j=0; j<4; j++)
        rightafterip[j] = afterip[j+4];

    for(i=0; i<4; i++)
    {
        index = ep[i];
        afterep[i] = rightafterip[index - 1];
    }

    for(i=4; i<8; i++)
    {
        index = ep[i];
        afterep[i] = rightafterip[index - 1];
    }
    afterep[i] = '\0';

    printf("\nAfter applying Expand Permutation :: ");
    for(i=0; i<8; i++)
        printf("%d ", afterep[i]);

    for(i=0; i<8; i++)
        k1[i] = k1[i] ^ afterep[i];

    printf("\n\nAfter apllying XOR Operation on 1st Key :: ");
    for(i=0; i<8; i++)
        printf("%d ", k1[i]);

    row = to_digit(k1[0],k1[3]);
    col = to_digit(k1[1],k1[2]);
    s0 = s_matrix0[row][col];

    to_binary(s0);
    for(j=0; j<2; j++)
        s0_binary[j] = result[j];

    row = to_digit(k1[4],k1[7]);
    col = to_digit(k1[5],k1[6]);

    s1 = s_matrix1[row][col];

    to_binary(s1);
    for(j=0; j<2; j++)
        s1_binary[j] = result[j];

    for(j=0; j<2; j++)
        aftersboxesone[j] = s0_binary[j];

    for(i=0,j=2; i<2,j<4; i++,j++)
        aftersboxesone[j] = s1_binary[i];

    printf("\n\nAfter applying First S-Boxes :: ");
    for(i=0; i<4; i++)
        printf("%d ", aftersboxesone[i]);

    printf("\n\nP4 Permutation Pattern :: ");
    for(i=0; i<4; i++)
        printf("%d ",p4[i]);

    for(i=0; i<4; i++)
    {
        index = p4[i];
        afterp4[i] = aftersboxesone[index - 1];
    }
    afterp4[i] = '\0';

    printf("\nAfter applying P4 Permutation :: ");
    for(i=0; i<4; i++)
        printf("%d ", afterp4[i]);

    for(i=0; i<4; i++)
        afterp4[i] = afterp4[i] ^ leftafterip[i];

    printf("\n\nAfter applying XOR Operation with left nibble after IP :: ");
    for(i=0; i<4; i++)
        printf("%d ", afterp4[i]);

    for(i=0; i<4; i++)
        afterone[i] = rightafterip[i];

    for(i=0,j=4; i<4,j<8; i++,j++)
        afterone[j] = afterp4[i];

    afterone[j] = '\0';

    printf("\nAfter first part :: ");
    for(i=0; i<8; i++)
        printf("%d ", afterone[i]);

    for(j=0; j<4; j++)
        leftafterone[j] = afterone[j];

    for(j=0; j<4; j++)
        rightafterone[j] = afterone[j+4];

    printf("\n\nExpand Permutation Pattern :: ");
    for(i=0; i<8; i++)
        printf("%d ",ep[i]);

    for(i=0; i<4; i++)
    {
        index = ep[i];
        afterep[i] = rightafterone[index - 1];
    }

    for(i=4; i<8; i++)
    {
        index = ep[i];
        afterep[i] = rightafterone[index - 1];
    }
    afterep[i] = '\0';

    printf("\nAfter applying Second EP :: ");
    for(i=0; i<8; i++)
        printf("%d ", afterep[i]);

    for(i=0; i<8; i++)
        k2[i] = k2[i] ^ afterep[i];

    printf("\n\nAfter applying XOR Operation with 2nd Key :: ");
    for(i=0; i<8; i++)
        printf("%d ", k2[i]);

    row = to_digit(k2[0],k2[3]);
    col = to_digit(k2[1],k2[2]);

    s0 = s_matrix0[row][col];
    to_binary(s0);
    for(j=0; j<2; j++)
        s0_binary[j] = result[j];

    row = to_digit(k2[4],k2[7]);
    col = to_digit(k2[5],k2[6]);

    s1 = s_matrix1[row][col];
    to_binary(s1);
    for(j=0; j<2; j++)
        s1_binary[j] = result[j];

    for(j=0; j<2; j++)
        aftersboxestwo[j] = s0_binary[j];

    for(i=0,j=2; i<2,j<4; i++,j++)
        aftersboxestwo[j] = s1_binary[i];

    printf("\n\nAfter applying Second S-Boxes :: ");
    for(i=0; i<4; i++)
        printf("%d ", aftersboxestwo[i]);

    printf("\n\nP4 Pattern :: ");
    for(i=0; i<4; i++)
        printf("%d ",p4[i]);

    for(i=0; i<4; i++)
    {
        index = p4[i];
        afterp4[i] = aftersboxestwo[index - 1];
    }
    afterp4[i] = '\0';

    printf("\nAfter applying P4 :: ");
    for(i=0; i<4; i++)
        printf("%d ", afterp4[i]);

    for(i=0; i<4; i++)
        afterp4[i] = afterp4[i] ^ leftafterone[i];

    printf("\n\nAfter applying XOR Operation with left nibble of after applying 1st part :: ");
    for(i=0; i<4; i++)
        printf("%d ", afterp4[i]);

    for(i=0; i<4; i++)
        aftertwo[i] = afterp4[i];

    for(i=0,j=4; i<4,j<8; i++,j++)
        aftertwo[j] = rightafterone[i];

    aftertwo[j] = '\0';

    printf("\n\nAfter applying Second Part :: ");
    for(i=0; i<8; i++)
        printf("%d ", aftertwo[i]);


    printf("\n\nInverse Initial Permutation Pattern :: ");
    for(i=0; i<8; i++)
        printf("%d ",ipinverse[i]);

    for(i=0; i<8; i++)
    {
        index = ipinverse[i];
        afteripinverse[i] = aftertwo[index - 1];
    }
    afteripinverse[j] = '\0';

    printf("\n\n---------------------------------------------");
    printf("\n || 8-bit Cipher Text :: ");
    for(i=0; i<8; i++)
        printf("%d ", afteripinverse[i]);
    printf("||\n----------------------------------------------\n\n");
}
