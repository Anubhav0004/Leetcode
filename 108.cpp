class Solution {
public:
    TreeNode *solve(vector<int> &v,int start,int end)
    {
        if(start>=end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode *root=new TreeNode(v[mid]);
        root->left=solve(v,start,mid);
        root->right=solve(v,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        TreeNode *root=solve(nums,0,nums.size());
        return root;
    }
};
