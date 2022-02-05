class Solution {
public:
    TreeNode *solve(vector<int> &preorder,int prestart,int preend,
                    vector<int> &inorder,int instart,int inend,map<int,int> &mp)
    {
        if(prestart>preend || instart>inend)    
            return NULL;
        TreeNode *root=new TreeNode(preorder[prestart]);
        int idx=mp[root->val]; //find the index of value in inorder array
        int numsleft=idx-instart; // values in left side of index
        root->left=solve(preorder,prestart+1,prestart+numsleft,inorder,instart,idx-1,mp);
        root->right=solve(preorder,prestart+numsleft+1,preend,inorder,idx+1,inend,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode *root=solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};
