class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        return solve(root->left,root->right);
    }
    bool solve(TreeNode *root1,TreeNode *root2)
    {
        if(!root1 && !root2)
            return true;
        if(!root1 || !root2)
            return false;
        if(root1->val!=root2->val)
            return false;
        return solve(root1->left,root2->right) && solve(root1->right,root2->left);
    }
};
