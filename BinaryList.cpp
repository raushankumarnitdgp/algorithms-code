//1000000007


long long unsigned int decimalValue(struct Node *head)
{
   // Your Code Here
  long long unsigned int res=0;
  while(head)
  {
    res=((res<<1)+head->data)%1000000007;
    head=head->next;
  }
  return res;
}