// 20BCE519 RAILFENCE Transposition Cipher
// Rail size is taken as 2.
#include<bits/stdc++.h>
using namespace std;

int main()
{
  char str[20]="RailFence", str1[10]="", str2[10]="", fstr[10];
  int i, cnt1=0, cnt2=0;
  cout <<"Plain Text :: RailFence\n";

  for(i=0; i<strlen(str); i++)
  {
    if( i%2 == 0)
    {
      str1[cnt1++]=str[i];
    }
    else
      str2[cnt2++]=str[i];
  }
  cout<<"Cipher Text :: "<<str1<<" "<<str2;

  return 0;
}
