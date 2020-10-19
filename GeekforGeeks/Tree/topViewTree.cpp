map<int,int> m;
void solve(Node* root){
    if(root==NULL)
    return;
    queue<pair<Node *,int>> q;
     
    q.push({root,0}); 
    
    
   
    while(!q.empty()){
        pair<Node *,int> tmp=q.front();
        q.pop();
        if(m.find(tmp.second)==m.end())
        m[tmp.second]=(tmp.first->data);
        if(tmp.first->left)
            q.push({tmp.first->left,tmp.second-1});
    
        if(tmp.first->right)
            q.push({tmp.first->right,tmp.second+1});
    
    }
}




void topView(struct Node *root)
{
    m.clear();
    solve(root);
    
    vector<int> v;    
    for(auto it=m.begin();it!=m.end();it++){
            cout<<it->second<<" ";
    }
 
        
}
