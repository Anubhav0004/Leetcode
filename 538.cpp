class Solution {
public:
    void solve(TreeNode *root,vector<TreeNode*> &v)
    {
        if(!root)
            return;
        solve(root->right,v);
        v.push_back(root);
        solve(root->left,v);
    }
    TreeNode* convertBST(TreeNode* root) 
    {
        if(!root)
            return NULL;
        vector<TreeNode*> v;
        solve(root,v);
        if(v.size()==1)
            return root;
        for(int i=1;i<v.size();i++)
        {
            v[i]->val+=v[i-1]->val;
        }
        return root;
    }
};
