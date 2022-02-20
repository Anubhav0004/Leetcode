TreeNode *link(TreeNode *root)
    {
        if(!root->left)
            return root->right;
        else if(!root->right)
            return root->left;
        TreeNode *rightchild=root->right;
        // TreeNode *leftchild=root->left;
        TreeNode *lr=lastright(root->left);
        lr->right=rightchild;
        return root->left;
    }
    TreeNode *lastright(TreeNode *root)
    {
        while(root->right!=NULL)
        {
            root=root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root)
            return NULL;
        if(root->val==key)
            return link(root);
        TreeNode *temp=root;
        while(root!=NULL)
        {
            if(root->val>key)
            {
                if(root->left && root->left->val==key)
                {
                    root->left=link(root->left);
                    break;
                }
                else
                    root=root->left;
            }
            else
            {
                if(root->right && root->right->val==key)
                {
                    root->right=link(root->right);
                    break;
                }
                else
                {
                    root=root->right;
                }
            }
        }
        return temp;
    }
