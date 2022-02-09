class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        if(!root1 && !root2)
            return true;
        if(!root1 || !root2)
            return false;
        vector<pair<int,int>> v1;
        vector<pair<int,int>> v2;
        queue<TreeNode*> q;
        
        v1.push_back({root1->val,root1->val});
        v2.push_back({root2->val,root2->val});
        
        q.push(root1);
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(temp->left)
            {
                v1.push_back({temp->val,temp->left->val});
                q.push(temp->left);
            }
            if(temp->right)
            {
                v1.push_back({temp->val,temp->right->val});
                q.push(temp->right);
            }
        }
        
        q.push(root2);
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(temp->left)
            {
                v2.push_back({temp->val,temp->left->val});
                q.push(temp->left);
            }
            if(temp->right)
            {
                v2.push_back({temp->val,temp->right->val});
                q.push(temp->right);
            }
        }
        
        if(v1.size()!=v2.size())
            return false;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        // for(int i=0;i<v1.size();i++)
        // {
        //     cout<<v1[i].first<<" "<<v1[i].second<<" "<<v2[i].first<<" "<<v2[i].second<<endl;
        // }
        for(int i=0;i<v1.size();i++)
        {
            auto x=v1[i];
            auto y=v2[i];
            if(x.first!=y.first || x.second!=y.second)
                return false;
        }
        
        return true;
    }
};
