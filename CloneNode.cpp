Node* copyList(Node *head)
{
     // Your code here
  
  if(head==0)
    return 0;
  
  Node* res=new Node;
  res->data=head->data;
  res->arb=head->arb;
  
  
  res->next=copyList(head->next);
  
  
  return res;
}