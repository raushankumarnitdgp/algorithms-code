#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
  int x=0,y=0;
  map<int, map <int,int> > m;
  m[x][y]=1;
  string s;
  cin>>s;
  
  int count=0;
  for(int i=0;i<=s.size();i++)
  {
    if(s[i]=='L')
    {
      if(m[x][y-1]==1)
      {
	count++;
      }
      m[x][y-1]=1;
      y=y-1;
    }
    else if(s[i]=='R')
    {
      if(m[x][y+1]==1)
      {
	count++;
      }
      m[x][y+1]=1;
      y=y+1;
    }
    else if(s[i]=='U')
    {
      if(m[x-1][y]==1)
      {
	count++;
      }
      m[x-1][y]=1;
      x=x-1;
    }
    else if(s[i]=='D')
    {
      if(m[x+1][y]==1)
      {
	count++;
      }
      m[x+1][y]=1;
      x=x+1;
    }
    else
    {
      m[x][y]=1;
    }
  }
  cout<<count<<endl;
  return 0;
}