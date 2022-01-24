class Solution {
public:
    int deepestLeavesSum(TreeNode* root) 
    {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        int size;
        int sum=0;
        q.push(root);
        while(!q.empty())
        {
            vector<int> t;
            size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                t.push_back(temp->val);
            }
            v.push_back(t);
        }
        for(int i=0;i<v[v.size()-1].size();i++)
        {
            sum+=v[v.size()-1][i];
        }
        return sum;
    }
};
