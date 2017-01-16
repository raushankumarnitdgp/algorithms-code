#include <iostream>

using namespace std;

double strToDouble(string s);

int main()
{
        string d1, d2;
        cout << "Enter two distances: \n";
        cin >> d1 >> d2;
        
	double D1=strToDouble(d1);
	double D2=strToDouble(d2);
	
        if(D1 < D2)
        {
                cout << "First distance is smaller"<< endl;
        }
        else if(D1 == D2)
        {
                cout << "Same distances"<< endl;
        }
        else
        {
                cout << "First distance is larger"<< endl;
        }
        return 0;
}

double strToDouble(string s)
{
        double expo = 1;
        double current = 0;
	double result  = 0;
        bool before = true;
	//in meter
	if(s[s.length()-1]=='m')
	{
	  for(int i=0; i < s.length()-1; i++)
	  {
		  if(s[i] == '.')
		  {
			  before= false;
			  continue;
		  }
		  
		  if(!before)
		  {
			  expo*=10;
		  }
		  current *= 10;
		  current += s[i]-'0';
		  result = current/expo; 
	  }
	}
	//or foot
        else
	{
	  before=true;
	  expo=1;
	  current=0;
	  result=0;
	  for(int i=0; i < s.length()-1; i++)
	  {
		  if(s[i] == 39 )
		  {
			  before= false;
			  continue;
		  }
		  
		  if(!before)
		  {
			  expo*=10;
		  }
		  current *= 10;
		  current += s[i]-'0';
		  result = current/expo; 
	  }
	  //cout<<"distance "<<result<<endl;
	  //converting foot in meter
	  int foot=result;
	  double inmtr;
	  double inches=result/foot;
	  inmtr=(foot + inches/12)*0.305;
	  result=inmtr;
	}
	
	return result;
}