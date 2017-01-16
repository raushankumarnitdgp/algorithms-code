#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin>>t;
  char res[500];
  while(t--)
  {
    string str1,str2;
    cin>>str1>>str2;
    int i=str1.size()-1;
    int j=str2.size()-1;
    for(int i=0;i<100;i++)
      res[i]='0';
    int carry=0;
    int k=0;
    while(i>=0 && j>=0)
    {
      int n=(str1[i]-'0'+str2[j]-'0'+carry)%2;
      carry=(str1[i]-'0'+str2[j]-'0'+carry)/2;
      res[k++]=n+'0';
      j--;
      i--;
    }
    
    while(i>=0)
    {
      int n=(str1[i]-'0'+carry)%2;
      carry=(str1[i]-'0'+carry)/2;
      res[k++]=n+'0';
      i--;
    }
    
    while(j>=0)
    {
      int n=(str2[j]-'0'+carry)%2;
      carry=(str2[j]-'0'+carry)/2;
      res[k++]=n+'0';
      j--;
    }
    
    if(carry==1)
      res[k++]=carry+'0';
    
    for(int l=k-1;l>=0;l--)
      cout<<res[l];
    cout<<endl;
    
  }
  return 0;
}