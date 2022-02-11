class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        queue<TreeNode*> q;
        int val=target->val;
        q.push(cloned);
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(temp->val==val)
                return temp;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return NULL;
    }
};
