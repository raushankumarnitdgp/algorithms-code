#include <bits/stdc++.h>
using namespace std;

int eggDrop(int n,int k,int **dp)
{
  if(n==1)
    return k;
  if(k<=1)
    return k;
  
  if(dp[n][k]!=-1)
    return dp[n][k];
  
  int minm=INT_MAX;
  int r;
  for(int i=1;i<=k;i++)
  {
    r=1+max(eggDrop(n-1,i-1,dp),eggDrop(n,k-i,dp));
    if(r < minm)
      minm=r;
  }
  
  dp[n][k]=minm;
  
  return dp[n][k];
  
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
      dp[i]=new int[k+1];
    
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=k;j++)
	dp[i][j]=-1;
    }
    cout<<eggDrop(n,k,dp)<<endl;
  }
  return 0;
}