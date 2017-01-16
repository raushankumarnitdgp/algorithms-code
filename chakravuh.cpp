#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
  int x;
  int y;
};
queue<Point> q;
void spiral(int **a,int m, int n)
{
    int i, k = 0, l = 0;
    int count=1;
    while (k < m && l < n)
    {
        
        for (i = l; i < n; ++i)
        {
            a[k][i]=count;
	    if(a[k][i]%11 == 0)
	    {
	      Point p;
	      p.x=k;
	      p.y=i;
	      q.push(p);
	    }
	    count++;
        }
        k++;
        
        for (i = k; i < m; ++i)
        {
           a[i][n-1]=count;
	   if(a[i][n-1]%11 == 0)
	    {
	      Point p;
	      p.x=i;
	      p.y=n-1;
	      q.push(p);
	    }
	   count++;
        }
        n--;
       
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
               a[m-1][i]=count;
	       if(a[m-1][i]%11 == 0)
		{
		  Point p;
		  p.x=m-1;
		  p.y=i;
		  q.push(p);
		}
	       count++;
            }
            m--;
        }
 
        
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                a[i][l]=count;
		if(a[i][l]%11 == 0)
		{
		  Point p;
		  p.x=i;
		  p.y=l;
		  q.push(p);
		}
		count++;
            }
            l++;    
        }        
    }
}











int main()
{
  int n;
  cin>>n;
  int **arr=new int*[n];
  for(int i=0;i<n;i++)
    arr[i]=new int[n];
  
  spiral(arr,n,n);
  int powerPoint=1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cout<<arr[i][j]<<" ";
      if(arr[i][j]%11 == 0)
	powerPoint++;
    }
  }
  
  cout<<"Total Power points : "<<powerPoint;
  
  cout<<"(0,0)";
  while(!q.empty())
  {
    Point P=q.front();
    cout<<"("<<P.x<<","<<P.y<<")";
    q.pop();
  }
  
  
  return 0;
}