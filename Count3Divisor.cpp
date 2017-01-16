#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  
  int *dp=new int[100000];
  for(int i=0;i<100000;i++)
    dp[i]=1;
  
  dp[0]=dp[1]=0;
  dp[2]=1;
  
  for(int j=2;j<1000;j++)
  {
    if(dp[j]==1)
    {
      for(int i=j;i*j < 100000 ;i++)
	dp[i*j]=0;
    }
  }
  
  for(int i=1;i<100000;i++)
    dp[i]+=dp[i-1];
  
  
  while(t--)
  { 
    int l,r;
    cin>>l>>r;
    cout<<dp[int(sqrt(r))]-dp[int(sqrt(l))]<<endl;
  }
  return 0;
}