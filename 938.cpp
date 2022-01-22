class Solution {
public:
    void inorder(TreeNode *root,vector<int> &v)
    {
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        vector<int> v;
        inorder(root,v);
        int sum=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>=low && v[i]<=high)
            {
                sum+=v[i];
            }
        }
        v.clear();
        return sum;
    }
};

///////////////////////////////////////////////////////////////BETTER APPROACH///////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        int sum=0;
        range(root,low,high,sum);
        return sum;
    }
    void range(TreeNode* root, int low, int high,int &sum) 
    {
        if(!root)
            return;
        if(root->val>=low && root->val<=high)
        {
            sum=sum+root->val;
        }
        range(root->left, low, high,sum);
        range(root->right, low, high,sum);
    }
    
};
