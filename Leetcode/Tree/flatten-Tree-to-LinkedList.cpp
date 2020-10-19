class Solution {
public:
    
    
    
    
    
    
    
    TreeNode* tmp=NULL;
    
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        
        if(root->right)
            flatten(root->right);
        
        if(root->left)
            flatten(root->left);
        
        root->left=NULL;
        root->right=tmp;
        tmp=root;
        
    }
};