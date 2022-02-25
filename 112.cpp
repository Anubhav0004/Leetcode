class Solution {
public:
    // int sum=0;
    bool hasPathSum(TreeNode* root, int targetSum) 
    { 
        if(!root)
            return false;
        targetSum-=root->val;
        if(!root->left && !root->right)
        {
            if(targetSum==0)
                return true;
        }
        // else 
        // {
            return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);
        // }
    }
};
