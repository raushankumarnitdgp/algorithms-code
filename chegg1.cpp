#include <bits/stdc++.h>
using namespace std;

class FinalExam
{
public:
  void set(int effort,double lck);
};


void FinalExam::set(int effort,double lck)
{
  cout<<"The Exam Score is "<<effort*lck<<endl;
}

char getGrade(double score)
{
  if(score <= 100 && score >= 90)
    return 'A';
  if(score < 90 && score >= 80)
    return 'A';
  if(score < 80 && score >= 70)
    return 'B';
  if(score < 70 && score >= 60)
    return 'C';
  if(score < 60 && score >= 50)
    return 'D';
  if(score < 50 && score >= 40)
    return 'P';
    return 'F';
}


int main()
{
  vector<double> luck(7);
  for(int i=0;i<7;i++)
  {
    cin>>luck[i];
  }
  //displaying luck vector
  cout<<"Displaying Luck Vector: "<<endl;
  for(int i=0;i<7;i++)
  {
    cout<<luck[i]<<" ";
  }
  cout<<endl;
  
  
  
  cout<<"What is your effort for the fianl exam ? ";
  int effort;
  cin>>effort;
  srand(time(NULL));

  double lck=luck[rand()%7];
  cout<<"What is your luck for the final exam? "<<lck<<endl;
  
  FinalExam E;
  E.set(effort,lck);
  cout<<"The Exam grade is "<<getGrade(effort*lck)<<endl;
  
  
  
  return 0;
}