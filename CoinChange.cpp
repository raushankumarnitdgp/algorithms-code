#include <bits/stdc++.h>
using namespace std;

int coinchange(int **dp,int arr[],int n,int sum)
{
  if(sum==0)
    return 1;
  
  if(n<=0)
    return 0;
  
  if(sum < arr[n-1])
  {
    if(dp[n][sum]==-1)
      dp[n][sum]=coinchange(dp,arr,n-1,sum);
    return dp[n][sum];
    
  }
  
  if(dp[n][sum]==-1)
  dp[n][sum]=(coinchange(dp,arr,n-1,sum) + coinchange(dp,arr,n,sum-arr[n-1]));
  
  return dp[n][sum];
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    
    int sum;
    cin>>sum;
    
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
      dp[i]=new int[sum+1];
    
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=sum;j++)
	dp[i][j]=-1;
    }
    
    cout<<coinchange(dp,arr,n,sum)<<endl;
  }
  return 0;
}