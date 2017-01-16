#include <iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int p,q,r;
    cin>>p>>q>>r;
    int *arr1=new int[p];
    int *arr2=new int[q];
    int *arr3=new int[r];
    
    for(int i=0;i<p;i++)
      cin>>arr1[i];
    
    for(int j=0;j<q;j++)
      cin>>arr2[j];
    
    for(int k=0;k<r;k++)
      cin>>arr3[k];
    
    int i=0,j=0,k=0;
    int count=0;
    
    while(i<p && j<q && k<r)
    {
      if(arr1[i] < arr2[j])
	i++;
      else if(arr1[i] > arr2[j])
	j++;
      else
      {
	while(k<r && arr3[k]<arr1[i])
	  k++;
	
	if(arr3[k]==arr1[i])
	{
	  cout<<arr1[i]<<" ";
	  count++;
	  k++;
	}
	
	i++;
	j++;
      }
    }
    cout<<endl;
    
  }
  return 0;
}