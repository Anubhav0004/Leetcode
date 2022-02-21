////////////////////////////////////////////////////EFFICIENT////////////////////////////////////////////////////////////////////

//////////////////////////////////////////ALTERNATE/////////////////////////////////////////
void solve(TreeNode *root,vector<int> &v)
    {
        if(!root)
            return;
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) 
    {
        if(!root->left && !root->right)
            return false;
        vector<int> v;
        solve(root,v);
        int i=0;
        int j=v.size()-1;
        while(true)
        {
            if(i>=j)
                return false;
            if(v[i]+v[j]==k)
                return true;
            else if(v[i]+v[j]<k)
                i++;
            else
                j--;
        }
        return false;
    }
//////////////////////////////////////////////////////////ALTERNATE////////////////////////////////////////////////////////////////
class Solution {
public:
    bool findTarget(TreeNode* root, int k) 
    {
        if(!root->left && !root->right)
            return false;
        unordered_map<int,int> mp;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            mp[temp->val]++;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int val=it->first;
            if(k-val!=val && mp.count(k-val))
                return true;
        }
        return false;
    }
};
/////////////////////////////////////////////////ALTERNATE APPROACH///////////////////////////////////////////////////////
class Solution {
public:
    void solve(TreeNode *root,vector<int> &v)
    {
        if(!root)
            return;
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) 
    {
        if(!root->left && !root->right)
            return false;
        vector<int> v;
        solve(root,v);
        for(int i=0;i<v.size()-1;i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                if(k-v[i]==v[j])
                    return true;
            }
        }
        return false;
    }
};
