class Solution {
public:
    void solve(TreeNode *root)
    {
//       100% solution
        if(root->left==NULL && root->right==NULL)
        {
            return;
        }
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        if(root->left!=NULL)
            solve(root->left);
        if(root->right!=NULL)
            solve(root->right);
    }
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root)
        {
            return NULL;
        }
        solve(root);
        return root;
    }
};
