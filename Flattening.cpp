

node* merge(node *a,node *b)
{
  if(a==0)
    return b;
  if(b==0)
    return a;
  
  
  node *res=0;
  if(a->data <= b->data)
  {
    res=a;
    res->bottom=merge(a->bottom,b);
    res->next=0;
  }
  else
  {
    res=b;
    res->bottom=merge(a,b->bottom);
    res->next=0;
  }
  
  return res;
  
}


node* flatten(node *root)
{
  if(root==0 || root->next==0)
    return root;
  return merge(root,flatten(root->next));
}