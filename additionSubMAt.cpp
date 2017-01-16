#include <iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n;
    cin>>m>>n;
    int** C=new int*[m];
    for(int i=0;i<m;i++)
      C[i]=new int[n];
    
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
	cin>>C[i][j];
    }
    
    
    
    int x1,y1,x2,y2;
    
    cin>>x1>>y1>>x2>>y2;
    
    int sum=0;
    for(int i=x1-1;i<x2;i++)
    {
      for(int j=y1-1;j<y2;j++)
	sum+=C[i][j];
    }
    cout<<sum<<endl;
  }
  return 0;
}