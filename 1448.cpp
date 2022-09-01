class Solution {
public:
    int search(TreeNode *root,int mx)
    {
        if(!root)
            return 0;
        int count=0;
        if(root->val>=mx)
        {
            count++;
            mx=root->val;
        }
        count+=search(root->left,mx);
        count+=search(root->right,mx);
        return count;
    }
    
    int goodNodes(TreeNode* root) 
    {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        int nodes=1;
        nodes+=search(root->left,root->val);
        nodes+=search(root->right,root->val);
        return nodes;
    }
};
