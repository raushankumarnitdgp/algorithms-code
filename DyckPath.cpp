#include <bits/stdc++.h>
using namespace std;

long long DyckPath(long long n)
{
  long long C=2*n;
  long long res=1;
  long long k  =1;
  while(k<=n)
  {
    res=res*C;
    res=res/k;
    C--;
    k++;
  }
  return (res/(n+1));
}



int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    long long n;
    cin>>n;
    cout<<DyckPath(n)<<endl;
  }
  return 0;
}