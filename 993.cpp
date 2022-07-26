class Solution {
public:
    int solve(TreeNode *root,int x,int &par,int height)
    {
        if(!root)
            return 0;
        if(root->val==x)
            return height;
        par=root->val;
        int left=solve(root->left,x,par,height+1);
        if(left)
            return left;
        par=root->val;
        int right=solve(root->right,x,par,height+1);
        return right;
    }
    bool isCousins(TreeNode* root, int x, int y) 
    {
        if(root->val==x||root->val==y)
            return false;
        int xp=-1,yp=-1;
        int xh=solve(root,x,xp,0);
        int yh=solve(root,y,yp,0);
        if(xh==yh && xp!=yp)
            return true;
        return false;
    }
};
