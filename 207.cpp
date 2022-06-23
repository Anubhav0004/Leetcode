class Solution { ////////////always use graph by reference//////////////////////
public:
    bool checkcycle(int node,vector<int> &vis,vector<int> &dfsvis,unordered_map<int,vector<int>> &mp)
    {
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it:mp[node])
        {
            if(!vis[it])
            {
                if(checkcycle(it,vis,dfsvis,mp))
                    return true;
            }
            else if(dfsvis[it])
                return true;
        }
        dfsvis[node]=0;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& v) 
    {
        vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<v.size();i++)
        {
            mp[v[i][1]].push_back(v[i][0]);
        }
        // if(n>mp.size())
        //     return true;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(checkcycle(i,vis,dfsvis,mp))
                    return false;
            }
        }
        return true;
    }
    
    //////////////solution 2/////////////////more efficient//////////////////////
    
    /*bool checkcycle(int node,vector<int> &vis,vector<vector<int>> &adj)
    {
        if(vis[node]==2)
            return true;
        vis[node]=2;
        for(auto it:adj[node])
        {
            if(vis[it]!=1)
            {
                if(checkcycle(it,vis,adj))
                    return true;
            }
        }
        vis[node]=1;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& v) 
    {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<v.size();i++)
        {
            adj[v[i][0]].push_back(v[i][1]);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(checkcycle(i,vis,adj))
                    return false;
            }
        }
        return true;
     }*/
};
