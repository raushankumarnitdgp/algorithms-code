

void BToDLL(Node *root,Node **head_ref)
{
  if(root==0)
    return 0;
  BToDLL(root->right,head_ref);
  root->right=*head_ref;
  
  if(*head_ref!=0)
    (*head_ref)->left=root;
  
  (*head_ref)=root;
  
  BToDLL(root->left,head_ref);
  
}