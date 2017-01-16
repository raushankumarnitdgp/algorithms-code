#include <bits/stdc++.h>
using namespace std;


bool isBothC(char a,char b)
{
  if(a>='A'&& a<='Z')
  {
    if(b>='A'&& b<='Z')
      return true;
  }
  return false;
}

bool isBothS(char a,char b)
{
  if(a>='a'&& a<='z')
  {
    if(b>='a'&& b<='z')
      return true;
  }
  return false;
}



void Sort(char *str)
{
  int n=strlen(str);
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(isBothC(str[i],str[j]) || isBothS(str[i],str[j]))
      {
	if(str[j]<str[i])
	{
	  char t=str[i];
	  str[i]=str[j];
	  str[j]=t;
	}
      }
    }
  }
}


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
    
    Sort(arr);
    cout<<arr<<endl;
  }
  return 0;
}