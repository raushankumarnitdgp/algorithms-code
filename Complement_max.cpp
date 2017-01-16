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
    char *arr=new char[n];
    cin>>arr;
    int l_i=-1;
    int r_i=-1;
    int l=0,r=0;
    int max=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
      if(arr[i]=='0')
      {
	count++;
	r=i;
      }
      else
      {
	count--;
	if(count<0)
	{
	  count=0;
	  l=i+1;
	}
      }
      
      if(max<count)
      {
	max=count;
	l_i=l;
	r_i=r;
      }
    }
    if(l_i==-1 && r_i == -1)
      cout<<"-1"<<endl;
    else
    cout<<l_i+1<<" "<<r_i+1<<endl;
  }
  return 0;
}