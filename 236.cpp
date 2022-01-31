class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL || root==p || root==q)
            return root;
        TreeNode *lft=solve(root->left,p,q);
        TreeNode *rt=solve(root->right,p,q);
        if(!lft)
            return rt;
        else if(!rt)
            return lft;
        else
            return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode *temp=solve(root,p,q);
        return temp;
    }
};
