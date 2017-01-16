#include <iostream>
using namespace std;

int max(int arr[],int l,int h)
{
  if(l==h)
    return l;
  if(h==l+1)
  {
    if(arr[l]>=arr[h])
      return l;
    return h;
  }
  
  int mid=(l+h)/2;
  
  if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1] )
    return mid;
  
  if(arr[mid] > arr[mid+1])
    return max(arr,l,mid-1);
  return max(arr,mid+1,h);
  
}

int find(int arr[],int l,int h,int x)
{
  if(l==h && arr[l]==x)
    return l;
  
  if(l<h)
  {
    int mid=(l+h)/2;
    if(arr[mid]==x)
      return mid;
    if(arr[mid]<x)
      return find(arr,mid+1,h,x);
    return find(arr,l,mid-1,x);
  }
  return -1;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    int index=max(arr,0,n-1);
    if(arr[index]==k)
      cout<<index<<endl;
    else
    {
      int i;
      if(k>=arr[0])
	i=find(arr,0,index-1,k);
      else
	i=find(arr,index+1,n-1,k);
      
      if(i==-1)
	cout<<"OOPS! NOT FOUND"<<endl;
      else
	cout<<i<<endl;
      
    }
  }
  return 0;
}