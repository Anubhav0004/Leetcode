class Solution {
public:
    void preorder(TreeNode* root,vector<TreeNode* >&v)
    {
        if(root->right==NULL && root->left==NULL)
        {
            v.push_back(root);
            return;
        }
        v.push_back(root);
        if(root->left!=NULL)
        {
            preorder(root->left,v);
        }
        if(root->right!=NULL)
        {
            preorder(root->right,v);
        }
    }
    void flatten(TreeNode* root) 
    {
        if(!root)
        {
            return;
        }
        vector<TreeNode*> v;
        preorder(root,v);
        TreeNode *temp= new TreeNode();
        for(int i=0;i<v.size()-1;i++)
        {
            TreeNode* temp=v[i];
            temp->right=v[i+1];
            temp->left=NULL;
        }
        v.clear();
    }
};
