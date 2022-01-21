class Solution {
public:
    void solve(TreeNode* root,vector<int>& v)
    {
        if(!root)
        {
            v.push_back(0);
            return;
        }
        v.push_back(root->val);
        solve(root->left,v);
        solve(root->right,v);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        vector<int> v1;
        vector<int> v2;
        solve(p,v1);
        solve(q,v2);
        if(v1.size()!=v2.size())
            return false;
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]!=v2[i])
            {
                v1.clear();
                v2.clear();
                return false;
            }
        }
        v1.clear();
        v2.clear();
        return true;
    }
};
