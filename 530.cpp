void solve(TreeNode *root,vector<int> &v)
    {
        if(!root)
            return;
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    int getMinimumDifference(TreeNode* root) 
    {
        vector<int> v;
        solve(root,v);
        // sort(v.begin(),v.end());
        int min=INT_MAX;
        for(int i=0;i<v.size()-1;i++)
        {
            int diff=abs(v[i]-v[i+1]);
            if(diff<min)
                min=diff;
        }
        return min;
    }
};
