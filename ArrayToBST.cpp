#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node* left;
  node* right;
  node()
  {
    data=0;
    left=0;
    right=0;
  }
};

node* createTree(node *root,int A[],int l,int h)
{
  if(l<=h)
  {
    int mid;
    if((l+h)%2 == 0)
      mid=(l+h)/2;
    else
      mid=(l+h)/2+1;
    root=new node;
    root->data=A[mid];
    root->right=createTree(root->right,A,l,mid-1);
    root->left=createTree(root->left,A,mid+1,h);
    return root;
  }
  return 0;
}

void preorder(node* root)
{
  if(root!=0)
  {
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
  }
  return ;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    
    node *root=createTree(root,arr,0,n-1);
    preorder(root);
    cout<<endl;
  }
}