
int getCount(struct Node* head)
{
  int count=0;
  while(head!=0)
  {
    count++;
    head=head->next;
  }
  return count;
}

int getIntersection(int d,struct Node* a,struct Node* b)
{
  while(d--)
  {
    if(a==0)
      return -1;
    a=a->next;
  }
  
  while(a!=0 && b!=0)
  {
    if(a == b)
      return a->data;
    a=a->next;
    b=b->next;
  }
  
  return -1;
  
}


int intersectPoint(struct Node* head1,struct Node* head2)
{
  int c1=getCount(head1);
  int c2=getCount(head2);
  
  if(c1>c2)
  {
    d=c1-c2;
    return getIntersection(d,head1,head2);
  }
  else
  {
    d=c2-c1;
    return getIntersection(d,head2,head1);
  }
  return -1;
}
