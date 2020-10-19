map<int,int> m;

void bottom(Node *root){
    if(root==NULL)
        return;
        
    queue<pair<Node*,int>> q;
    q.push({root,0});
    
    while(!q.empty()){
        pair<Node*,int> tmp = q.front() ;
        q.pop();
        m[tmp.second]=(tmp.first->data);    
    
        if(tmp.first->left)
            q.push({tmp.first->left,tmp.second-1});
            
        if(tmp.first->right)
            q.push({tmp.first->right,tmp.second+1});    

    }
}




vector <int> bottomView(Node *root)
{
    m.clear();
    bottom(root);
    vector<int> v;
    for(auto itr=m.begin();itr!=m.end();itr++){
        v.push_back(itr->second);
    }
    return v;
    
}
