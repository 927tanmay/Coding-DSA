Node* successor(Node* root){
    if(root==NULL)
        return root;
    
    while(root && root->left){
        root=root->left;
    }    
    return root;
}


Node *deleteNode(Node *root,  int x)
{
    if(root==NULL)
        return root;
        
    if(root->data>x)    
        root->left=deleteNode(root->left,x);
    else
        if(root->data<x)
            root->right=deleteNode(root->right,x);
    else{
           if(root->left==NULL){
            Node* tmp = root->right;
            free(root);
            return tmp;
        }
        
        if(root->right==NULL){
            Node* tmp = root->left;
            free(root);
            return tmp;
        }
        
        if(root->left && root->right){
            Node*tmp = successor(root->right);
            root->data=tmp->data;
            root->right=deleteNode(root->right,tmp->data);
        }
        
     
    }
    return root;            
}
