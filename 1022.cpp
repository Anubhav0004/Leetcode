class Solution {
public:
    int solve(TreeNode *root,int val)
    {
        if(!root)
            return 0;
        val=(val*2+root->val);
        return root->left==root->right ? val : solve(root->left,val)+solve(root->right,val);
            
    }
    int sumRootToLeaf(TreeNode* root) 
    {
        return solve(root,0);
    }
};
