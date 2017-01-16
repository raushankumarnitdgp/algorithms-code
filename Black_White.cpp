#include <bits/stdc++.h>
using namespace std;


int countAttack(bool **visited,int x,int y,int m,int n)
{
  int count=0;
  int Arx[8]={2,1,-1,-2,-2,-1,1,2};
  int Ary[8]={1,2,2,1,-1,-2,-2,-1};
  
  for(int i=0;i<8;i++)
  {
    if(x+Arx[i]<=m-1 && x+Arx[i]>=0)
    {
      if(y+Ary[i]<=n-1 && y+Ary[i]>=0)
      {
	if(visited[x+Arx[i]][y+Ary[i]]==false)
	  count++;
      }
    }
  }
  return count;
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n;
    cin>>m>>n;
    bool **visited=new bool*[m];
    for(int i=0;i<m;i++)
      visited[i]=new bool[n];
    
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
	visited[i][j]=false;
    }
    
    int possible=n*m;
    
    int count=0;
    
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
	visited[i][j]=true;
	count+=countAttack(visited,i,j,m,n);
      }
    }
    
    cout<<possible*(possible-1)-2*count<<endl;
    
  }
  return 0;
}