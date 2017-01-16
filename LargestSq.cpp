#include <bits/stdc++.h>
using namespace std;

int min(int a,int b,int c)
{
  return min(a,min(b,c));
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n;
    cin>>m>>n;
    int **matrix=new int*[m];
    for(int i=0;i<m;i++)
      matrix[i]=new int[n];
    
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
	cin>>matrix[i][j];
    }
    
    for(int i=1;i<m;i++)
    {
      for(int j=1;j<n;j++)
      {
	if(matrix[i][j])
	  matrix[i][j]=min(matrix[i][j-1],matrix[i-1][j-1],matrix[i-1][j])+1;
      }
    }
    
    int max=0;
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
	if(max<matrix[i][j])
	  max=matrix[i][j];
      }
    }
    
    cout<<max<<endl;
    
    
  }
  return 0;
}