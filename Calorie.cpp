#include <bits/stdc++.h>
using namespace std;

int main()
{
  int NumCookiesinP , NumServP ,CalorieinServ ,Tcookies;
  
  
  
  cout<<"Enter the number of cookies in this package :"<<endl;
  cin>>NumCookiesinP;
  
  cout<<"Enter the number of serving per package :"<<endl;
  cin>>NumServP;
  
  cout<<"Enter the number of calories in One serving :"<<endl;
  cin>>CalorieinServ;
  
  cout<<"Enter the number of cookies you consumed:"<<endl;
  cin>>Tcookies;
  
  
  
  
  
  float totalPackage = Tcookies/NumCookiesinP ;
  float totalCaloriesConsum = totalPackage*NumServP*CalorieinServ ;
  float CaloriesPCookie = totalCaloriesConsum/Tcookies ;
  
  
  
  
  
  cout<<endl<<"OutPut"<<endl;
  cout<<"Total Calories Consumed "<<totalCaloriesConsum<<endl;
  cout<<"Number of Calories per Cookies "<<CaloriesPCookie<<endl;
  return 0;
}