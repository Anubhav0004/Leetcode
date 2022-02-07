class Solution {
public:
    void inorder(TreeNode *root,vector<TreeNode *> &v)
    {
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }
    TreeNode* increasingBST(TreeNode* root) 
    {
        if(!root->left && !root->right)
            return root;
        vector<TreeNode*> v;
        inorder(root,v);
        root=v[0];
        TreeNode *temp;
        for(int i=0;i<v.size()-1;i++)
        {
            temp=v[i];
            temp->left=NULL;
            temp->right=v[i+1];
        }
        temp->right->left=NULL;
        temp->right->right=NULL;
        v.clear();
        return root;
    }
};
