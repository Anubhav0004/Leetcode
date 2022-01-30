class Solution { ////////////////////////////////100% solution///////////////////////////////////////
public:
    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        int l;
        while(!q.empty())
        {
            vector<int>v;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                v.push_back(temp->val);
            }
            l=v[0];
        }
        return l;
    }
};
