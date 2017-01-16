#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;


bool is_special(string s)
{
  int i=0;
  int j=s.size()/2;
  while(j<s.size())
  {
    if(s[i]!=s[j])
    {
      return false;
    }
    i++;
    j++;
  }
  return true;
}

bool isSpecial_(string s,int i)
{
  int j=0;
  int k=s.size()/2;
  if(i<=k)
    k=k+1;
  
  while(k<s.size())
  {
    if(j==i)
    {
      j++;
      continue;
    }
    
    if(k==i)
    {
      k++;
      continue;
    }
    
    if(s[k]!=s[j])
      return false;
    k++;
    j++;
  }
  return true;
}

bool isSpecial(string s)
{
  for(int i=0;i<s.size();i++)
  {
    if(isSpecial_(s,i)==true)
      return true;
  }
  return false;
}

int main()
{
  string s;
  int t;
  cin>>t;
  while(t--)
  {
    cin>>s;
    if(s.size()%2==0)
    {
     if(is_special(s))
     {
       cout<<"YES"<<endl;
     }
     else
       cout<<"NO"<<endl;
    }
    else
    {
      if(isSpecial(s))
      {
	cout<<"YES"<<endl;
      }
      else
      {
	cout<<"NO"<<endl;
      }
    }
  }
  return 0;
}
