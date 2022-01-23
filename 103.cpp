class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        queue<TreeNode*> q;
        vector<vector<int>> v;
        if(!root)
            return v;
        
        int count=0;
        int size=0;
        q.push(root);
        TreeNode *temp;
        while(!q.empty())
        {
            size=q.size();
            vector<int> t;
            for(int i=0;i<size;i++)
            {
                temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                t.push_back(temp->val);
            }
            if(count%2!=0)
            {
                reverse(t.begin(),t.end());
            }
            count++;
            v.push_back(t);
        }
        return v;
    }
};
