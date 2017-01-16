#include <iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,b;
    cin>>n>>b;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    
    for(int i=0;i<n;i++)
    {
      if(arr[i]==b)
	b=b*2;
    }
    
    cout<<b<<endl;
    
  }
  return 0;
}