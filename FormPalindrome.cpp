#include <bits/stdc++.h>
using namespace std;


int FormPalindrome(int **dp,string str,int l,int h)
{
  if(l>=h)
    return 0;
  
  if(dp[l][h]!=-1)
    return dp[l][h];
  
  if(str[l]==str[h])
  {
    dp[l][h]=FormPalindrome(dp,str,l+1,h-1);
    return dp[l][h];
  }
  
  dp[l][h]=1+min(FormPalindrome(dp,str,l+1,h),FormPalindrome(dp,str,l,h-1));
  return dp[l][h];
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string str;
    cin>>str;
    int **dp=new int*[str.size()];
    for(int i=0;i<str.size();i++)
      dp[i]=new int[str.size()];
    
    for(int i=0;i<str.size();i++)
    {
      for(int j=0;j<str.size();j++)
      {
	dp[i][j]=-1;
      }
    }
    
    cout<<FormPalindrome(dp,str,0,str.size()-1)<<endl;
    
  }
  return 0;
}