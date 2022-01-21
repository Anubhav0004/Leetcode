class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> v;
        if(!root)
        {
            return v;
        }
        vector<int> t;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(temp!=NULL)
            {
                t.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            else if(!q.empty())
            {
                v.push_back(t);
                t.clear();
                q.push(NULL);
            }  
        }
        if(t.size()!=0)
            {
                v.push_back(t);
            }
        reverse(v.begin(),v.end());
        return v;
    }
};
