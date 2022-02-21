///////////////////////////////////////////////////////////////////EFFICIENT/////////////////////////////////////////////////////
stack<TreeNode*> st;
    BSTIterator(TreeNode* root) 
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
    }
    
    int next() 
    {
        TreeNode *node=st.top();
        TreeNode *temp=st.top();
        st.pop();
        if(!temp->right)
            return node->val;
        temp=temp->right;
        while(temp)
        {
            st.push(temp);
            temp=temp->left;
        }
        return node->val;
    }
    
    bool hasNext() 
    {
        return !st.empty();
    }
////////////////////////////////////ALTERNATE/////////////////////////////////////////////////
vector<int> v;
    int i=-1;
    void solve(TreeNode *root)
    {
        if(!root)
            return;
        solve(root->left);
        v.push_back(root->val);
        solve(root->right);
    }
    BSTIterator(TreeNode* root) 
    {
        solve(root);    
    }
    
    int next() 
    {
        i++;
        return v[i];
    }
    
    bool hasNext() 
    {
        if(i==-1)
            return true;
        if(i<v.size()-1)
            return true;
        return false;
    }
