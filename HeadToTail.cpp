#include <bits/stdc++.h>
using namespace std;


void dfs(bool **adj,int index,int n,bool *visited)
{
  visited[index]=true;
  for(int i=0;i<n;i++)
  {
    if(!visited[i] && adj[index][i])
    {
      dfs(adj,i,n,visited);
    }
  }
  return ;
}


int findDeg0(bool **adj,int n)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(adj[j][i]==1)
	break;
    }
    if(j==n)
      return i;
  }
  return 0;
}


bool isAllVisited(bool *visited,int n)
{
  for(int i=0;i<n;i++)
  {
    if(visited[i]==false)
      return false;
  }
  return true;
}

  
bool isTravAll(bool **adj,int index,int n)
{
  bool *visited=new bool[n];
  for(int i=0;i<n;i++)
    visited[i]=false;
  
  dfs(adj,index,n,visited);
  
  if(isAllVisited(visited,n))
    return true;
  return false;
}
  
  
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string *str=new string[n];
    for(int i=0;i<n;i++)
      cin>>str[i];
    bool **adj=new bool*[n];
    
    for(int i=0;i<n;i++)
    {
      adj[i]=new bool[n];
    }
    
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
	adj[i][j]=0;
      }
    }
    
    
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
	if(i!=j)
	{
	  if(str[i][str[i].size()-1]==str[j][0])
	    adj[i][j]=1;
	}
      }
    }
    
    int index=findDeg0(adj,n);
    if(isTravAll(adj,index,n))
      cout<<"Head to tail ordering is possible."<<endl;
    else
      cout<<"Head to tail ordering is not possible."<<endl;
  }
  return 0;
}