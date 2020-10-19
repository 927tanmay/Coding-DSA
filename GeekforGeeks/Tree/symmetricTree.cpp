bool mirrorImage(struct Node* root1,struct Node* root2){
    if(root1==NULL && root2==NULL)
        return true;
        
    if(root1==NULL || root2==NULL)    
        return false;
        
    return (root1->data==root2->data) && mirrorImage(root1->left,root2->right) && mirrorImage(root1->right,root2->left);         
}


bool isSymmetric(struct Node* root)
{
	return mirrorImage(root,root);
}