#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  string s;
  cin>>s;
  
  int count=0;
  for(int i=0;i<s.size()-2;)
  {
    if(s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='0')
    {
      count++;
      i=i+3;
    }
    else
      i++;
  }
  cout<<count;
  return 0;
}