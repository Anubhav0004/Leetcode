class Solution {
public:
    void inorder(TreeNode *root,vector<TreeNode*> &v)
    {
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }
    TreeNode* bstToGst(TreeNode* root) 
    {
        vector<TreeNode*> v;
        inorder(root,v);
        if(v.size()==1)
            return root;
        reverse(v.begin(),v.end());
        int sum=v[0]->val;
        for(int i=1;i<v.size();i++)
        {
            v[i]->val+=sum;
            sum=v[i]->val;
        }
        return root;
    }
};
