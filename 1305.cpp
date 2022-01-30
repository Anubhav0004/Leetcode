class Solution {
public:
    vector<int> v;
    void solve(TreeNode *root)
    {
        if(!root)
            return;
        solve(root->left);
        v.push_back(root->val);
        solve(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        if(!root1 && !root2)
            return v;
        solve(root1);
        solve(root2);
        sort(v.begin(),v.end());
        return v;
    }
};
