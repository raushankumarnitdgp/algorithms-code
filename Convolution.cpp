#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define m 5		//modify it 8x8


int Result[m][m];

void addpadding(int **input,int n)
{
  int i=m-n-1;
  int j=m-n-1;
  int k,l;
  for(k=0;k<n;k++,i++)
  {
    for(l=0,j=m-n-1;l<n;l++,j++)
      Result[i][j]=input[k][l];
  }
  
}


int convolve(int kernel[3][3],int i,int j)
{
  int res1=kernel[0][0]*Result[i-1][j-1]  + kernel[0][1]*Result[i-1][j]  + kernel[0][2]*Result[i-1][j+1];
  int res2=kernel[1][0]*Result[i][j-1]  + kernel[1][1]*Result[i][j]  + kernel[1][2]*Result[i][j+1];
  int res3=kernel[2][0]*Result[i+1][j-1]  + kernel[2][1]*Result[i+1][j]  + kernel[2][2]*Result[i+1][j+1];
  //Result[i][j]=res1+res2+res3;
  return res1+res2+res3;
}

int main()
{
  int kernel[3][3]={1,2,1,
		    0,0,0,
		  -1,-2,-1
		   };
  printf("Enter the input array size:\n");
  int n,i,j;
  scanf("%d",&n);
  int **input=(int **)malloc(sizeof(int*)*n);
  for(i=0;i<n;i++)
    input[i]=(int *)malloc(sizeof(int)*n);
  
  
  printf("Enter the value in input array:\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      scanf("%d",&input[i][j]);
  }
  
  //paddwith 0s
  for(i=0;i<m;i++)
  {
    for(j=0;j<m;j++)
      Result[i][j]=0;
  }
  
  
  addpadding(input,n);
  
  //now Result array have the value
  
  int k=m-n-1;
  int l=m-n-1;
  for(i=0,k=m-n-1;i<n;i++,k++)
  {
    
    for(j=0,l=m-n-1;j<n;j++,l++)
    {
      input[i][j]=convolve(kernel,k,l);
    }
  }
  
  printf("\n\n Convolved Matrix: \n\n");
  //convolved matrix
  
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      cout<<input[i][j]<<" ";
    cout<<endl;
  }
  
  
  
  return 0;
}