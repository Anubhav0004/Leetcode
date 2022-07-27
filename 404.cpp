class Solution {/////////////////100%solution/////////////
public:
    bool isleaf(TreeNode *root)
    {
        return root->left==root->right;
    }
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(!root)
            return 0;
        else if(root->left && isleaf(root->left))
        {
            return root->left->val+sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }
};
