#include <bits/stdc++.h>
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
    int res=1;
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      res=res^arr[i];
    }
    res=res^1;
    cout<<res<<endl;
  }
  return 0;
}





