#include <bits/stdc++.h>
using namespace std;

int min( int x, int y, int z) 
{
  return min(min(x, y), z);
}



int makeSame(int **dp,string str1,string str2,int len1,int len2)
{
  if(len1==0)
    return len2;
  
  if(len2==0)
    return len1;
  
  if(str1[len1-1]==str2[len2-1])
  {
    if(dp[len1][len2]==-1)
      dp[len1][len2]=makeSame(dp,str1,str2,len1-1,len2-1);
    
    return dp[len1][len2];
  }
  
  if(dp[len1][len2]==-1)
      dp[len1][len2]=1+min(makeSame(dp,str1,str2,len1-1,len2-1),makeSame(dp,str1,str2,len1,len2-1),makeSame(dp,str1,str2,len1-1,len2));
   
  return dp[len1][len2];
}





int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int len1,len2;
    cin>>len1>>len2;
    string str1,str2;
    cin>>str1>>str2;
    len1=str1.length();
    len2=str2.length();
    int **dp=new int*[len1+1];
    for(int i=0;i<=len1;i++)
      dp[i]=new int[len2+1];
    
    for(int i=0;i<=len1;i++)
    {
      for(int j=0;j<=len2;j++)
	dp[i][j]=-1;
    }
    
    cout<<makeSame(dp,str1,str2,str1.length(),str2.length())<<endl;
  
    
  }
  
  
  return 0;
}