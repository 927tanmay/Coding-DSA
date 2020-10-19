void leftView(Node *root)
{
   queue<Node *> q;
   if(root)
   q.push(root);
   
   while(!q.empty()){
       
       
       int size=q.size();
       int chk=size;
       while(size){
        Node *tmp=q.front();
        q.pop();
        if(size==chk)
         cout<<tmp->data<<" ";
        if(tmp->left)
            q.push(tmp->left);
        
        if(tmp->right)
            q.push(tmp->right);
            
        size--;
       }
       
   }
}