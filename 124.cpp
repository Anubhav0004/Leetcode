class Solution {
public:
    int solve(TreeNode *root, int &sum)
    {
        if(!root)
            return 0;
        int l=max(0,solve(root->left,sum));
        int r=max(0,solve(root->right,sum));
        
        sum=max(sum,l+r+root->val);
        
        return root->val + max(l,r);
    }
    // int maxPathDown(TreeNode* node, int &maxi) {
    //     if (node == NULL) return 0;
    //     int left = max(0, maxPathDown(node->left, maxi));
    //     int right = max(0, maxPathDown(node->right, maxi));
    //     maxi = max(maxi, left + right + node->val);
    //     return max(left, right) + node->val;
    // }
    int maxPathSum(TreeNode* root) 
    {
        int sum=INT_MIN;
        solve(root,sum);
        return sum; 
    }
};
