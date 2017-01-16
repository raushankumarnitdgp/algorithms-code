
void reverse(Node **head)
{
  Node *prev=0,*curr=*head,*next;
  while(curr)
  {
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  
  *head=prev;
}


Node *compute(Node *head)
{
  if(head==0)
    return 0;
  reverse(&head);
  int max=head->data;
  Node *prev=head;
  
  Node *t=head->next;
  while(t!=0)
  {
    if(t->data>=max)
    {
      max=t->data;
      prev=t;
      t=t->next
    }
    else
    {
      prev->next=t->next;
      t=t->next;
    }
  }
  reverse(&head);
  return head;
}