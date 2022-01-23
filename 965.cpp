class Solution {
public:
  ////////////////////////100% solution////////////////////////////
    bool solve(TreeNode *root,int val)
    {
        if(!root)
            return true;
        if(root->val!=val)
            return false;
        return solve(root->left,val) && solve(root->right,val);
    }
    bool isUnivalTree(TreeNode* root) 
    {
        int val=root->val;
        int ans=solve(root,val);
        return ans;
    }
};
