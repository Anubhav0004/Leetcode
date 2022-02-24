class Solution {
public:
//////////////////////////////////////////////////////100% solution////////////////////////////////////////////////////////////
    int sum=0;
    void solve(TreeNode *root,int prev)
    {
        if(!root->left && !root->right)
        {
            int temp=10*prev+root->val;
            sum+=temp;
            return;
        }
        if(root->left)
            solve(root->left,prev*10+root->val);
        if(root->right)
            solve(root->right,prev*10+root->val);
    }
    int sumNumbers(TreeNode* root) 
    {
        solve(root,0);
        return sum;
    }
};
