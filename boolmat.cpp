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
    int** mat=new int*[m];
    for(int i=0;i<m;i++)
      mat[i]=new int[n];
   
    int t;
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
          t=1;
    	if(mat[i][j]==1)
    	  {
    	      cin>>t;
    	  }
	else
	  cin>>mat[i][j];
	if(mat[i][j]==1&&t==1)
	{
	  for(int k=0;k<n;k++)
	    mat[i][k]=1;
	  for(int k=0;k<m;k++)
	    mat[k][j]=1;
	}
      }
    }
    
    
    
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
	cout<<mat[i][j]<<" ";
    }
     cout<<endl;
  }
  return 0;
}