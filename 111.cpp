class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        if(!root)
            return 0;
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        return 1+(min(left,right)?min(left,right):max(left,right));
    }
};
