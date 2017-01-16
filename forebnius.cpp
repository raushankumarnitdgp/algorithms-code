#include <iostream>
using namespace std;

int gcd(int a,int b)
{
  if(b==0)
    return a;
  return gcd(b,a%b);
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int a,b;
    cin>>a>>b;
    int A,N;
    int hcf=gcd(a,b);
    if(hcf!=1)
    {
      cout<<"NA"<<endl;
    }
    else
    {
      A=(a*b)-(a+b);
      N = (a-1)*(b-1)/2;
      cout<<A<<" "<<N<<endl;
    }
  }
  return 0;
}