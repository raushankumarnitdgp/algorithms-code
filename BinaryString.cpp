#include <bits/stdc++.h>
using namespace std;


int count1(string str)
{
  int count=0;
  for(int i=0;i<str.size();i++)
  {
    if(str[i]=='1')
      count++;
  }
  return count;
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string str;
    cin>>str;
    int m=count1(str);
    cout<<m*(m-1)/2<<endl;
  }
  return 0;
}