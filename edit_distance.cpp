#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int min(int x, int y, int z) 
{
   return min(min(x, y), z);
}






int editDist(string str1,string str2,int m,int n)
{
  if(m==0)
    return n;		//n insertion will work
   
  if(n==0)
    return m;		//m insertion will work
  
  if(str1[m-1]==str2[n-1])
    return editDist(str1,str2,m-1,n-1);		//same then no edition required
  
  return(1+ min(editDist(str1,str2,m-1,n-1),editDist(str1,str2,m,n-1),editDist(str1,str2,m-1,n)));
  
}

int editDist_i(string str1,string str2,int m,int n)
{
  
  int **solution=new int*[m+1];
  for(int i=0;i<=m;i++)
    solution[i]=new int[n+1];
  
  for(int i=0;i<=m;i++)
    solution[i][0]=i;
  for(int j=0;j<=n;j++)
    solution[0][j]=j;
  
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(str1[i-1]==str2[j-1])
	solution[i][j]=solution[i-1][j-1];
      else
      {
	solution[i][j]=1+min(solution[i-1][j-1],solution[i-1][j],solution[i][j-1]);
      }
    }
  }
  
  return solution[m][n];
}


int main()
{
    // your code goes here
    string str1;
    string str2;
    cin>>str1>>str2;
 
    cout << editDist( str1 , str2 , str1.length(), str2.length())<<endl;
 
    return 0;
}


