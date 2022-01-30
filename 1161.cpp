class Solution {
public:
    int maxLevelSum(TreeNode* root) 
    {
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty())
        {
            int sum=0;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                sum+=temp->val;
            }
            v.push_back(sum);
        }
        int lvl=0;
        int max=-1000000;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>max)
            {
                max=v[i];
                lvl=i;
            }
        }
        return lvl+1;
    }
};
