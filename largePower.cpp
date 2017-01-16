#include <bits/stdc++.h>
using namespace std;


int power(int A,int B,int C)
{
  if(B==1)
    return A%C;
  if(B%2==0)
  {
    int sum=power(A,B/2,C)%C;
    return (sum*sum)%C;
  }
  else
  {
    int sum=power(A,(B-1)/2,C)%C;
    return (((sum*sum)%C)*A)%C;
  }
}



int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int A,B,C;
    cin>>A>>B>>C;
    cout<<power(A,B,C)<<endl;
  }
  return 0;
}