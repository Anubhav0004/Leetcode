int i=0;
    int ans;
    void inorder(TreeNode *root,int k)
    {
        if(!root)
            return;
        inorder(root->left,k);
        i++;
        if(i==k)
            ans=root->val;
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        inorder(root,k);
        return ans;
    }
///////////////////////////////////////////MY APPROACH//////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root,int k)
    {
        if(v.size()>k)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(root->val);
            return;
        }
        if(root->left!=NULL)
        {
            inorder(root->left,k);
        }
        v.push_back(root->val);
        if(root->right!=NULL)
        {
            inorder(root->right,k);
        }
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        int val;
        inorder(root,k);
        val=v[k-1];
        return val;
    }
};
