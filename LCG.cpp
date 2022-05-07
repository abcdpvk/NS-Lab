#include <bits/stdc++.h>
using namespace std;

void linearCongruentialMethod(
    int Xo, int m, int a, int c,
    vector<int>& randomNums,
    int noOfRandomNums)
{

    randomNums[0] = Xo;

    for (int i = 1; i < noOfRandomNums; i++) {

        randomNums[i]
            = ((randomNums[i - 1] * a) + c) % m;
    }
}

int main()
{
    cout<<"\n\t\t\t\t\t***********Practical 5.1 LCG************\n\n\n";
    int Xo; // Seed value
    int m ; // Modulus parameter
    int a ; // Multiplier term
    int c ; // Increment term
    cout<<"Enter Seed Value :: ";
    cin>>Xo;
    cout<<"Enter Modulus :: ";
    cin>>m;
    cout<<"Enter Multiplier :: ";
    cin>>a;
    cout<<"Enter Increment :: ";
    cin>>c;

    int noOfRandomNums = 20;


    vector<int> randomNums(
        noOfRandomNums);


    linearCongruentialMethod(
        Xo, m, a, c,
        randomNums, noOfRandomNums);


     cout << "Random Numbers :: ";
    for (int i = 0; i < noOfRandomNums; i++) {
        cout << randomNums[i] << " ";
    }

    return 0;
}
