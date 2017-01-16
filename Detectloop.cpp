int detectloop(struct node *list)
{
  node *slow=list;
  node *fast=list;
  while(slow && fast && fast->next)
  {
    slow=slow->next;
    fast=fast->next->next;
    if(fast==slow)
      return 1;
  }
  return 0;
}