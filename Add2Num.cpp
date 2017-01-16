void reverse(node **head)
{
  node *prev=0,*curr=*head,*next;
  while(curr)
  {
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  
  *head=prev;
}



int getLength(node *l)
{
  int count=0;
  while(l!=0)
  {
    count++;
    l=l->next;
  }
  return count;
}




node* paddZero(node *s,int len)
{
  if(s==0)	
    return 0;
  node *head=new node;
  head->data=0;
  head->next=0;
  len--;
  node *temp=head;
  while(len--)
  {
    temp->next=new node;
    temp->next->data=0;
    temp=temp->next;
  }
  node* t=s;
  while(t->next)
    t=t->next;
  t->next=head;
  return s;
}


struct node* addTwoLists(struct node* first,struct node* second)
{
    if(first==0)
    return second;
    if(second==0)
    return first;
  //reverse(first);
  //reverse(second);
  int l1=getLength(first);
  int l2=getLength(second);
  if(l1>l2)
    second=paddZero(second,abs(l1-l2));
  else
    first=paddZero(first,abs(l2-l1));
  
  node* a=first;
  node* b=second;
  int carry=0;
  node* prev=0;
  while(a!=0&&b!=0)
  {
    a->data=a->data+b->data+carry;
    if(a->data/10)
      carry=1;
    else
      carry=0;
    a->data=a->data%10;
    prev=a;
    a=a->next;
    b=b->next;
  }
  
  if(carry)
  {
    node* c=new node;
    c->data=carry;
    c->next=0;
    prev->next=c;
  }
  //reverse(&first);
  return first;
}




struct node* res = NULL; // res is head node of the resultant list
struct node *temp, *prev = NULL;
int carry = 0, sum;
 
while (first != NULL || second != NULL) //while both lists exist
{
// Calculate value of next digit in resultant list.
// The next digit is sum of following things
// (i) Carry
// (ii) Next digit of first list (if there is a next digit)
// (ii) Next digit of second list (if there is a next digit)
sum = carry + (first? first­>data: 0) + (second? second­>data: 0);
 
// update carry for next calulation
carry = (sum >= 10)? 1 : 0;
 
// update sum if it is greater than 10
sum = sum % 10;
 
// Create a new node with sum as data
temp = newNode(sum);
 
// if this is the first node then set it as head of the resultant list
if (res == NULL)
res = temp;
else // If this is not the first node then connect it to the rest.
prev­>next = temp;
 
// Set prev for next insertion
prev = temp;
 
// Move first and second pointers to next nodes
if (first) first = first­>next;
if (second) second = second­>next;
}
 
if (carry > 0)
temp­>next = newNode(carry);
return res;




