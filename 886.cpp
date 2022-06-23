class Solution {
public:
    
    bool bipartitebfs(int node,vector<int> &vis,unordered_map<int,vector<int>> mp)
    {
        vis[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            for(auto it:mp[top])
            {
                if(vis[it]==-1)
                {
                    vis[it]=1-vis[top];
                    q.push(it);
                }
                else if(vis[it]==vis[top])
                    return false;
            }
        }
        return true;
    }
    
    /*bool bipartitedfs(int node,vector<int> &vis,unordered_map<int,vector<int>> mp)
    {
        if(vis[node]==-1)
            vis[node]=1;
        for(auto it:mp[node])
        {
            if(vis[it]==-1)
            {
                vis[it]=1-vis[node];
                if(!bipartitedfs(it,vis,mp))
                    return false;
            }
            else if(vis[it]==vis[node])
                return false;
        }
        return true;
    }*/
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<dislikes.size();i++)
        {
            int key=dislikes[i][0]-1;
            int val=dislikes[i][1]-1;
            mp[key].push_back(val);
            mp[val].push_back(key);
        }
        // int n=mp.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                if(!bipartitebfs(i,vis,mp))
                    return false;
                
                //DFS WILL NOT WORK HERE DUE TO CONSTRAINTS
                // if(!bipartitedfs(i,vis,mp))
                //     return false;
            }
        }
        return true;
    }
};
