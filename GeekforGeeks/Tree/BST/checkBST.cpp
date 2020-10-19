int tmp;bool flag;

void inorder(Node* root){
    if(root==NULL)
     return ;
     
    
        
    if(root->left)
      inorder(root->left);
      
    
    if(tmp>=root->data)
     flag=false;
     else{
     tmp=root->data;
     }
    
    if(root->right)
       inorder(root->right);
}


bool isBST(Node* root) {
    flag=true;
    tmp=INT_MIN;
    inorder(root);
    return flag;
}
