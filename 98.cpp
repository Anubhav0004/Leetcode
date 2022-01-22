class Solution 
{
public:
    void inorder(TreeNode *root,vector<int> &v)
    {
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool isValidBST(TreeNode* root) 
    {  
        vector<int> v;
        inorder(root,v);
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i+1]<=v[i])
            {
                v.clear();
                return false;
            }
        }
        v.clear();
        return true;
    }
};
/////////////////////////////////////////// BETTER APPROACH /////////////////////////////////////////////////////////
class Solution {
public:
    bool compare(TreeNode* root, long min,long max)
    {
        if(!root)
            return true;
        if(root->val<=min || root->val>=max)
            return false;
        return compare(root->left,min,root->val) && compare(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) 
    {
        bool ans=compare(root,LONG_MIN,LONG_MAX);
        return ans;
    }
};
