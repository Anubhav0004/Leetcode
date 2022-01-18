class Solution {
public:
    TreeNode *root1=NULL;
    void search(TreeNode *root,int val)
    {
        if(root->val==val)
        {
            root1=root;
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return;
        }
        if(root->left!=NULL && val<root->val )
        {
            search(root->left,val);
        }
        if(root->right!=NULL && val>root->val)
        {
            search(root->right,val);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        search(root,val);
        return root1;
    }
};
