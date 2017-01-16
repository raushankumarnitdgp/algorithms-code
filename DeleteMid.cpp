struct Node* deleteMid(struct Node* head)
{
  if(head==0)
    return 0;
  node *mid=head;
  node *fast=head;
  node *prev=0;
  while(fast!=0 && fast->next!=0)
  {
    fast=fast->next->next;
    prev=mid;
    mid=mid->next;
  }
  
  if(prev->next==0)
    return 0;
  
  prev->next=mid->next;
  free(mid);
  
  return head;
  
}