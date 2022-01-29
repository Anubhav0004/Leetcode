class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> v;
        if(!root)
            return v;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            TreeNode *temp=q.front().first;
            int ln=q.front().second.first;
            int lvl=q.front().second.second;
            q.pop();
            mp[ln][lvl].insert(temp->val);
            if(temp->left)
                q.push({temp->left,{ln-1,lvl+1}});
            if(temp->right)
                q.push({temp->right,{ln+1,lvl+1}});
        }
        for(auto it : mp)
        {
            vector<int> col;
            for(auto i : it.second)
                col.insert(col.end(),i.second.begin(),i.second.end());
            v.push_back(col);
        }
        return v;
    }
};
