#include <bits/stdc++.h>
using namespace std;


int lcs(int **dp,string str1,string str2,int m,int n)
{
  if(m==0||n==0)
    return 0;
  
  if(dp[m][n]!=-1)
    return dp[m][n];
  
  if(str1[m-1]==str2[n-1])
  {
    dp[m][n]=1+lcs(dp,str1,str2,m-1,n-1);
    return dp[m][n];
  }
  
  dp[m][n]=max(lcs(dp,str1,str2,m-1,n),lcs(dp,str1,str2,m,n-1));
  return dp[m][n];
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n;
    cin>>m>>n;
    string str1,str2;
    cin>>str1>>str2;
    int **dp=new int*[m+1];
    for(int i=0;i<=m;i++)
      dp[i]=new int[n+1];
    
    for(int i=0;i<=m;i++)
    {
      for(int j=0;j<=n;j++)
	dp[i][j]=-1;
    }
    
    cout<<lcs(dp,str1,str2,str1.length(),str2.length())<<endl;
    
  }
  return 0;
}
