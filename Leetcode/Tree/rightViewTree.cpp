void rightView(Node *root)
{
   if(root==NULL)
    return;
   
   queue<Node*> q;
   q.push(root);
   
   
   while(!q.empty()){
       int size=q.size();
  
       
       while(size>0){
           Node* tmp=q.front();
           q.pop();
           
           if(tmp->left)
            q.push(tmp->left);
           
           if(tmp->right)
            q.push(tmp->right);
            
      
           if(size==1)
           cout<<tmp->data<<" ";
           size--;    
       }
       
   }
}
