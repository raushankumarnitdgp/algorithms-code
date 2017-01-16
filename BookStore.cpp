#include <bits/stdc++.h>
using namespace std;

int main()
{
  float book1_prc=89;
  float book2_prc=119;
  float book3_prc=49;
  
  float total=book1_prc+book2_prc+book3_prc;
  float tax=total*0.05;
  
  float amount=total+tax;
  
  cout<<"Payable amount:"<<amount<<endl;
  
  return 0;
}