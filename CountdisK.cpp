#include <iostream>
#include <algorithm>
using namespace std;


int count(int arr[],int n,int k)
{
  int c=0;
  int l=0,r=0;
  while(r<n)
  {
    if((arr[r]-arr[l])==k && r!=l)
    {
      c++;
      r++;
      l++;
      if(k==0 && r<n)
      {
	while(arr[r]==arr[l])
	{
	  r++;
	  l++;
	}
      }
    }
    else if(arr[r]-arr[l] > k)
    {
      l++;
    }
    else
      r++;
  }
  return c;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    int k;
    cin>>k;
    sort(arr,arr+n);
    cout<<count(arr,n,k)<<endl;
  }
  return 0;
}