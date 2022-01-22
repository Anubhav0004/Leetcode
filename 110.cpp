class Solution {
public:
    int solve(TreeNode *root)
    {
        if(!root)
        {
            return 0;
        }
        
        int lh=solve(root->left);
        if(lh==-1) 
            return -1;
        
        int rh=solve(root->right);
        if(rh==-1) 
            return -1;
        
        if(abs(lh-rh)>1) 
            return -1;
        
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) 
    {
        if(!root)
        {
            return true;
        }
        int ans=solve(root);
        if(ans==-1) return false;
        return true;
    }
};
