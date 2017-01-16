#include <bits/stdc++.h>
using namespace std;


int findMaxsum(int **arr,int n)
{
  int sum[n];
  for(int i=0;i<n;i++)
  {
    int d=max(arr[0][i],arr[1][i]);
    if(i-3 >=0)
      sum[i]=d+max(sum[i-2],sum[i-3]);
    else if(i-2 >= 0)
      sum[i]=d+sum[i-2];
    else
      sum[i]=d;
  }
  return max(sum[n-1],sum[n-2]);
}


int FindMaxsum(int **arr,int n)
{
  if(n<=0)
    return 0;
  
  int ele=max(arr[0][n-1],arr[1][n-1]);
  
  return (ele +max(FindMaxsum(arr,n-2),FindMaxsum(arr,n-3)));
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int **arr=new int*[2];
    
    arr[0]=new int[n];
    arr[1]=new int[n];
    
    for(int i=0;i<2;i++)
      for(int j=0;j<n;j++)
	cin>>arr[i][j];
    
    cout<<FindMaxsum(arr,n)<<endl;
      
  }
  return 0;
}