#include <iostream>
#include <algorithm>
using namespace std;

class ItemInStore
{
public:
  int w;	//weight
  int v;	//corresponding value
};


//modified compare function to sort in decreasing order of v/w

bool myCompare(ItemInStore x,ItemInStore y)
{
  float a=(float)x.v / x.w;
  float b=(float)y.v / y.w;
  return ( a > b );
}


int main()
{
  cout<<"Enter the Capacity of Bag "<<endl;
  int W;
  cin>>W;
  int n;
  cout<<"Enter the number of Items Available in Store:"<<endl;
  cin>>n;
  ItemInStore *ItemAvail=new ItemInStore[n];
  
  cout<<"Enter the Corresponding Weight and Value of n Item Avail "<<endl;
  
  for(int i=0;i<n;i++)
    cin>>ItemAvail[i].w>>ItemAvail[i].v;
  
  //now sort item based on v/w ratio decreasing order
  
  sort(ItemAvail,ItemAvail+n,myCompare);
  
  int curWt = 0; 
  float res = 0;
 
 
  for (int i = 0; i < n; i++)
  {
        if (curWt + ItemAvail[i].w <= W)
        {
            curWt += ItemAvail[i].w;
            res += ItemAvail[i].v;
        }
 
        //  add fractional part,if whole cannot be added
        else
        {
            int rem = W - curWt;
            res += ItemAvail[i].v * ((float) rem / ItemAvail[i].w);
            break;
        }
  }
  
  cout<<"Maximum value that can be stored in Bag with Capacity "<<W<<" value = "<<res<<endl;
  
  return 0;
}