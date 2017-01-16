#include <iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  char c;
  while(t--)
  {
    string str;
    cin>>str;
    
    
    for(int i=0;i<str.size();i++)
    {
      if(str[i] >= 'A' && str[i] <= 'Z')
      {
	if(i!=0)
	cout<<" ";
	c=str[i]-'A'+'a';
	cout<<c;
      }
      else
      {
	cout<<str[i];
      }
    }
    
    cout<<endl;
      
  }
  return 0;
}