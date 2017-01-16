#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

int main()
{
  string input;
  string output;
  
  string dictionary[]={"Alpha","Bravo","Charlie","Delta","Echo","Foxtrot","Golf"};
  //complete the dicitionary you want to use.
  
  cout<<"Enter the input to get encrypted "<<endl;
  cin>>input;
  if(input[0]-'a'>=0)
  {
    //building encrypted output with help of dicitionary
    output=dictionary[input[0]-'a'];
  }
  else
  {
    output=dictionary[input[0]-'A'];
  }
  for(int i=1;i<input.size();i++)
  {
    //building encrypted output with help of dicitionary
    if(input[i]-'a'>=0)
    {
      output=output+dictionary[input[i]-'a'];
    }
    else
    {
      output=output+dictionary[input[i]-'A'];
    }
  }
  
  cout<<"Encrypted Ouput: "<<output<<endl;
  
  return 0;
}