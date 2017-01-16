#include <iostream>
#include <algorithm>
using namespace std;

int count(int p,int q,int r,int ball)
{
  if (p<0 || q<0 || r<0)
    return 0;

  
  if(ball==0 && p==1 && q==0 && r==0)
    return 1;
  if(ball==1 && p==0 && q==1 && r==0)
    return 1;
  if(ball==2 && p==0 && q==0 && r==1)
    return 1;
  
  if(ball==0)
  return (count(p-1,q,r,1)+count(p-1,q,r,2));
  
  if(ball==1)
  return (count(p,q-1,r,0)+count(p,q-1,r,2));
  
  if(ball==2)
  return (count(p,q,r-1,0)+count(p,q,r-1,1));
  
}

int countDp(int p,int q,int r)
{
  int dp[p+1][q+1][r+1][3];
  
  for(int i=0;i<=p;i++)
  {
    for(int j=0;j<=q;j++)
    {
      for(int k=0;k<=r;k++)
      {
	dp[i][j][k][0]=0;
	dp[i][j][k][1]=0;
	dp[i][j][k][2]=0;
      }
    }
  }
  
  dp[1][0][0][0]=1;
  dp[0][1][0][1]=1;
  dp[0][0][1][2]=1;
  
  for(int i=0;i<=p;i++)
  {
    for(int j=0;j<=q;j++)
    {
      for(int k=0;k<=r;k++)
      {
	if(k>0)
	dp[i][j][k][2]=max(dp[i][j][k][2],dp[i][j][k-1][0]+dp[i][j][k-1][1]);
	if(j>0)
	dp[i][j][k][1]=max(dp[i][j][k][1],dp[i][j-1][k][0]+dp[i][j-1][k][2]);
	if(i>0)
	dp[i][j][k][0]=max(dp[i][j][k][0],dp[i-1][j][k][1]+dp[i-1][j][k][2]);
      }
    }
  }
  
  return dp[p][q][r][0]+dp[p][q][r][1]+dp[p][q][r][2];
  
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int p,q,r;
    cin>>p>>q>>r;
    int res=countDp(p,q,r);
    cout<<res<<endl;
  }
  return 0;
}