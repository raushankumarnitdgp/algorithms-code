void deleteNode(Node *node)
{
  Node *d=node->next;
  node->data=d->data;
  node->next=d->next;
  delete(d);
}


void reverse(struct node **head_ref)
{
  node *temp=0;
  node *current = (*head_ref);
  while(current!=0)
  {
    temp=current->prev;
    current->prev=current->next;
    current->next=temp;
    current=current->prev;
  }
  
  if(temp!=0)
    *head_ref = temp->prev;
  
}