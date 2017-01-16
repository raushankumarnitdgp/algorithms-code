#include <iostream>
using namespace std;

int inBetween(int ht[],int i,int j)
{
 int min;
 if(ht[i]<ht[j])
   min=ht[i];
 else
   min=ht[j];
 int capacity=0;
 for(int k=i+1;k<j;k++)
 {
   if(ht[k]<=min)
   capacity+=min-ht[k];
 }
 return capacity;
}

int water(int h[],int n)
{
  int capacity=0,max_l=0,max_r=0,max_l_i=0,max_r_i=0;
  int i=0;
  bool increasing=true;
  
  while(i<n)
  {
      while(increasing && i<n)
      {
	if(h[i]>=max_l)
	{
	  max_l=h[i];
	  max_l_i=i;
	  increasing=true;
	}
	else
	{
	  increasing=false;
	}
	i++;
      }
      
      max_r=0,max_r_i=0;
      while(i<n)
      {
	if(h[i]>=max_r)
	{
	  max_r=h[i];
	  max_r_i=i;
	}
	i++;
	if(max_r>=max_l)
	  break;
      }
      
      capacity=capacity+inBetween(h,max_l_i,max_r_i);
      if(max_r_i)
      {
	i=max_r_i;
	increasing=true;
	max_l=0;
      }
  }
  return capacity;
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int* ht=new int[n];
    for(int i=0;i<n;i++)
      cin>>ht[i];
    
    cout<<water(ht,n)<<endl;
    
  }
  return 0;
}