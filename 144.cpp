class Solution {
public:
    void solve(TreeNode* root,vector<int>& v)
    {
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(root->val);
            return;
        }
        // int val=root->val;
        v.push_back(root->val);
        if(root->left!=NULL)
        {
            solve(root->left,v);
        }
        if(root->right!=NULL)
        {
            solve(root->right,v);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) 
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
