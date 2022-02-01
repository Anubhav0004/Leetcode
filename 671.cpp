class Solution {
public:
    void solve(TreeNode *root,vector<int> &v)
    {
        if(!root)
            return;
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    int findSecondMinimumValue(TreeNode* root) 
    {   
        vector<int> v;
        solve(root,v);
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i+1]>v[i])
            {
                return v[i+1];
            }
        }
        return -1;
    }
};
