TreeNode* build(vector<int> &v,int &i,int bound)
    {                           ////////////////////EFFICIENT//////////////////////
        if(i==v.size() || v[i]>bound)
            return NULL;
        TreeNode *root=new TreeNode(v[i++]);
        root->left=build(v,i,root->val);
        root->right=build(v,i,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
///////////////////////////////////////////////MY APPROACH////////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode *solve(vector<int> &preorder,int prestart,int preend,
                   vector<int> &inorder,int instart,int inend,map<int,int> &mp)
    {
        if(prestart>preend || instart>inend)
            return NULL;
        TreeNode *root=new TreeNode(preorder[prestart]);
        int idx=mp[root->val];
        int numsleft=idx-instart;
        root->left=solve(preorder,prestart+1,prestart+numsleft,inorder,instart,idx-1,mp);
        root->right=solve(preorder,prestart+numsleft+1,preend,inorder,idx+1,inend,mp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        vector<int> inorder;
        for(int i=0;i<preorder.size();i++)
        {
            inorder.push_back(preorder[i]);
        }
        sort(inorder.begin(),inorder.end());
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode *root=solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};
