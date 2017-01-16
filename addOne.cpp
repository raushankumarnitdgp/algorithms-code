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


void addOneU(Node **head)
{
  Node *temp=*head;
  int carry=0;
  Node *prev;
  while(temp)
  {
    temp->data=temp->data+1+carry;
    if(head->data / 10)
      carry=head->data/10;
    prev=temp;
    temp=temp->next;
  }
  if(carry)
  {
    Node *c=new Node;
    c->data=carry;
    c->next=0;
    prev->next=c;
  }
  
}



Node *addOne(Node *head)
{
  reverse(&head);
  addOneU(&head);
  reverse(&head);
  return head;
}