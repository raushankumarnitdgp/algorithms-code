
#include <bits/stdc++.h>
using namespace std;


int main()
{
  int *Array=new int[1000];
  for(int i=0;i<1000;i++)
    Array[i]=0;
  
  int *Start_address=&Array[0];
  int *End_address  =&Array[999];
  printf("Start_address at %p\n", Start_address);
  printf("End_address at %p  \n", End_address);
  
  FILE *fp;
  
  fp=fopen("Start_addr.txt","w");
  fprintf(fp,"%p",Start_address);
  fclose(fp);
  
  
  fp=fopen("End_addr.txt","w");
  fprintf(fp,"%p",End_address);
  fclose(fp);
  
  while(1)
  {
    for(int i=0;i<1000;i++)
      Array[i]+=1;
  }
  
  return 0;
}