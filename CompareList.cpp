int compare(Node *list1,Node *list2)
{
  if(list1 == 0 && list2 == 0)
    return 0;
  
  if(list2==0)
    return 1;
  
  if(list1 == 0)
    return -1;
  
  if(list1->c > list2->c)
    return 1;
  
  if(list2->c > list1->c)
    return -1;
  
  return compare(list1->next , list2->next);
  
}