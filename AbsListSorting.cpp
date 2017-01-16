void sortList(Node **head)
{
  Node *prev=(*head);
  Node *curr=(*head)->next;
  while(curr!=0)
  {
    if(curr->data < prev->data)
    {
      prev->next=curr->next;
      curr->next=(*head);
      (*head)=curr;
      curr=prev;
    }
    else
    {
      prev=curr;
    }
    curr=curr->next;
  }
}



