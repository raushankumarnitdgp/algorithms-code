#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    
    sort(arr,arr+n);
    
    int sum=9999999;
    int l=0,r=n-1;
    
    int l_,r_;
    while(l<r)
    {
      if(abs(sum) > abs(arr[l]+arr[r]))
      {
	sum=arr[l]+arr[r];
	l_=l;
	r_=r;
      }
      if(arr[l]+arr[r] > 0)
      {
	r--;
      }
      else
      {
	l++;
      }
      
    }
    
    cout<<arr[l_]<<" "<<arr[r_]<<endl;
   
  }
  return 0;
}