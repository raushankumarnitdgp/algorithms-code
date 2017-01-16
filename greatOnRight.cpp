#include <iostream>
using namespace std;

void print(int arr[],int n,int max)
{
  if(n==0)
    return ;
  
  if(max<arr[n-1])
    print(arr,n-1,arr[n-1]);
  else
    print(arr,n-1,max);
  cout<<max<<" ";
}

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
    
    print(arr,n,-1);
    cout<<endl;
  }
  return 0;
}