#include <bits/stdc++.h>
using namespace std;

int myCmp(string a,string b)
{
  string ab=a.append(b);
  string ba=b.append(a);
  
  return ab.compare(ba)>0?1:0;
}



int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string *arr=new string[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    sort(arr,arr+n,myCmp);
    for(int i=0;i<n;i++)
      cout<<arr[i];
    cout<<endl;
  }
  return 0;
}

