#include <iostream>
using namespace std;

int eggDrop(int n,int k)
{
  if(n==1)
    return k;
  if(k==0||k==1)
    return k;
  int minm=9999;
  for(int x=0;x<=k;x++)
  {
    int r=1+max(eggDrop(n-1,x-1),eggDrop(n,k-x));
    if(r<minm)
      minm=r;
  }
  return minm;
}


int eggDrop_(int n,int k)
{
  int S[n+1][k+1];
  for(int i=1;i<=n;i++)
  {
    S[i][1]=1;
    S[i][0]=0;
  }
  for(int j=1;j<=k;j++)
    S[1][j]=j;
  
  for(int i=2;i<=n;i++)
  {
    for(int j=2;j<=k;j++)
    {
      int minm=9999;
      for(int x=1;x<=j;x++)
      {
	int r=1+max(S[i-1][x-1],S[i][j-x]);
	if(r<minm)
	  minm=r;
      }
      S[i][j]=minm;
    }
  }
  return S[n][k];
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    cout<<eggDrop_(n,k)<<endl;
  }
  return 0;
}