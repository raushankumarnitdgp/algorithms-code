#include <iostream>
using namespace std;

void print(int n)
{
  char c='A';
  if(n<=26)
  {
    c=c+n-1;
    cout<<c;
    return ;
  }
  int r=n%26;
  if(r==0)
    print(n/26 -1);
  else
    print(n/26);
  
  if(r==0)
    cout<<'Z';
  else
  {
    c=c+r-1;
    cout<<c;
  }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    print(n);
    cout<<endl;
  }
  return 0;
}