#include <iostream>
using namespace std;

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
    {
      cin>>arr[i];
    }
    
    cout<<arr[0]<<" ";
    
    int i=1,j=1;
    
    while( i<n && j<n )
    {
      while(arr[j]>=0 && j<n)
      {
	j++;
      }
      if(j<n)
      cout<<arr[j]<<" ";
      
      while(arr[i]<0 && i<n)
      {
	i++;
      }
      if(i<n)
      cout<<arr[i]<<" ";
      i++;
      j++;
    }
    cout<<endl;

  }
  
  return 0;
  
}