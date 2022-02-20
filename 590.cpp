void solve(Node *root,vector<int> &v)
    {
        if(!root)
            return;
        for(int i=0;i<root->children.size();i++)
        {
            solve(root->children[i],v);
        }
        v.push_back(root->val);
    }
    vector<int> postorder(Node* root) 
    {
        vector<int> v;
        if(!root)
            return v;
        solve(root,v);
        return v;
    }
