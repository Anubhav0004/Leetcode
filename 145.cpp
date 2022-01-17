class Solution {
public:
    void solve(TreeNode *root,vector<int>& v)
    {
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(root->val);
            return;
        }
        int val=root->val;
        if(root->left!=NULL)
        {
            solve(root->left,v);
        }
        if(root->right!=NULL)
        {
            solve(root->right,v);
        }
        v.push_back(val);
    }
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> v;
        if(!root)
        {
            return v;
        }
        solve(root,v);
        return v;
    }
};
