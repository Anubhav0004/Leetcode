class Solution {
public:
    void solve(TreeNode *root,vector<vector<int>> &v,int k,vector<int> &temp)
    {
        if(!root)
            return;
        temp.push_back(root->val);
        k-=root->val;
        if(!root->left && !root->right)
        {
            if(k==0)
                v.push_back(temp);
        }
        else
        {
            solve(root->left,v,k,temp);
            solve(root->right,v,k,temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> v;
        if(!root)
            return v;
        vector<int> temp;
        solve(root,v,targetSum,temp);
        return v;
    }
};
