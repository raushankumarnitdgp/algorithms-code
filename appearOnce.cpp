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
    int *arr=new int[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    int res=arr[0];
    for(int i=1;i<n;i++)
      res=res^arr[i];
    cout<<res<<endl;
  }
  return 0;
}