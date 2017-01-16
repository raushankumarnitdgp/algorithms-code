#include <iostream>
#include <stdio.h>
using namespace std;


int min(int a, int b)
{
    return (a<b)? a: b;
}


int binomialCoeff(int n,int k)
{
  if(k==0)
    return 1;
  if(k==n)
    return 1;
  
  return (binomialCoeff(n-1,k)+binomialCoeff(n-1,k-1));
}

int binomialCoeff_i(int n,int k)
{
  int C[n+1][k+1];
  
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=min(i,k);j++)
    {
      if(j==0||j==i)
	C[i][j]=1;
      else
	C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
  }
  return C[n][k];
}

int main()
{
   int n = 5, k = 2;
   printf ("Value of C(%d, %d) is %d ", n, k, binomialCoeff_i(n, k) );
   return 0;
}