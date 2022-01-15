class Solution {
public:
    void inorder(TreeNode *root,vector<int>& v)
    {
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(root->val);
            return;
        }
        int val=root->val;
        if(root->left!=NULL)
        {
            inorder(root->left,v);
        }
        v.push_back(val);
        if(root->right!=NULL)
        {
            inorder(root->right,v);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> v;
        if(!root)
        {
            return v;
        }
        inorder(root,v);
        return v;
    }
};
