class Solution {
public:
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> v;
        if(!root)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int max=q.front()->val;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                if(max<temp->val)
                    max=temp->val;
            }
            v.push_back(max);
        }
        return v;
    }
};
