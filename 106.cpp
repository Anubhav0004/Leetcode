class Solution {
public:
    TreeNode *solve(vector<int>& inorder,int instart,int inend,
                   vector<int>& postorder,int pstart,int pend,map<int,int> &mp)
    {
        if(instart>inend || pstart>pend)
            return NULL;
        TreeNode *root=new TreeNode(postorder[pend]);
        int idx=mp[root->val];
        int numsleft=idx-instart;
        root->left=solve(inorder,instart,idx-1,postorder,pstart,pstart+numsleft-1,mp);
        root->right=solve(inorder,idx+1,inend,postorder,pstart+numsleft,pend-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode *root=solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
        return root;
    }
};
