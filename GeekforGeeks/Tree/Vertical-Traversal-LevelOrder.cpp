map<int,vector<int>> m;
void solve(Node* root,int d){
    if(root==NULL)
    return;
    queue<pair<Node *,int>> q;
     
    q.push({root,0}); 
    
    
   
    while(!q.empty()){
        pair<Node *,int> tmp=q.front();
        q.pop();
        m[tmp.second].push_back(tmp.first->data);
        if(tmp.first->left)
            q.push({tmp.first->left,tmp.second-1});
    
        if(tmp.first->right)
            q.push({tmp.first->right,tmp.second+1});
    
    }
}




vector<int> verticalOrder(Node *root)
{   m.clear();
    solve(root,0);
    // cout<<endl;
    vector<int> v;    
    for(auto it=m.begin();it!=m.end();it++){
        for(auto b = it->second.begin(); b != it->second.end() ;b++)
            v.push_back(*b);
            
    
    }
   return v;
}
