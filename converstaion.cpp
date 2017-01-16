#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<fstream>
#include<string>
using namespace std;

int main()
{
   ifstream File;
   File.open("word.txt");
  
  string Sub[20];
  string verb[20];
  string obj[20];
  string arr[100];
  ofstream myfile;
  myfile.open ("output.txt");
  
  int i=0,j=0,k=0,l=0;
  while(!File.eof())
  {
        File>>arr[i];
	if(arr[i]=="Subject")
	  File>>Sub[j++];
	else if(arr[i]=="verb")
	  File>>verb[k++];
	else if(arr[i]=="object")
	  File>>obj[l++];
        i++;
  }
  
  //printing List of Object
  /*for(int i=0;i<20;i++)
    if(obj[i]!="")
    cout<<obj[i]<<endl;
  */
  
  srand(time(NULL));
  myfile<<Sub[rand()%j]<<" "<<verb[rand()%k]<<" "<<obj[rand()%l]<<endl;
  
  
  
  return 0;
}