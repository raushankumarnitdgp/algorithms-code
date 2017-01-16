#include <bits/stdc++.h>
using namespace std;



int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    int *arr=new int[n];
    int *dp=new int[n];
    for(int i=0;i<n;i++)
      dp[i]=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      if(arr[i]>k)
      dp[i]=i+1;
      else
	dp[i]=dp[i-1];
      
      sum=sum+dp[i];
    }
    cout<<sum<<endl;
  }
 return 0; 
}
