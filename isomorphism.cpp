#include <iostream>
using namespace std;

int main()
{
  string str1,str2;
  int t;
  cin>>t;
  while(t--)
  {
      cin>>str1>>str2;
      char dict1[26] ,dict2[26];
      for(int i=0;i<26;i++)
      {
	dict1[i]='-';
	dict2[i]='-';
      }
      
      int i;
      for(i=0;i<str1.size();i++)
      {
	if(dict1[str1[i]-'a']=='-' && dict2[str2[i]-'a']=='-')
	{
	  dict1[str1[i]-'a']=str2[i];
	  dict2[str2[i]-'a']=str1[i];
	}
	else
	{
	  if(str2[i]!=dict1[str1[i]-'a'] )
	  {
	    cout<<"0"<<endl;
	    break;
	  }
	}
      }
      if(i==str1.size())
	cout<<"1"<<endl;
  }
  return 0;
}