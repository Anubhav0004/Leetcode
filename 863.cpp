class Solution {
public:
    void parent(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &mp)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(temp->left)
            {
                mp[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                mp[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode*,TreeNode*> mp;
        parent(root,mp);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        int d=0;
        q.push(target);
        visited[target]=true;
        while(!q.empty())
        {
            int size=q.size();
            if(d++==k)  break;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !visited[temp->left])
                {
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right && !visited[temp->right])
                {
                    q.push(temp->right);
                    visited[temp->right]=true;
                }
                if(mp[temp] && !visited[mp[temp]])
                {
                    q.push(mp[temp]);
                    visited[mp[temp]]=true;
                }
            }
        }
        vector<int> v;
        while(!q.empty())
        {
            TreeNode *curr=q.front();
            q.pop();
            v.push_back(curr->val);
        }
        return v;
    }
};
