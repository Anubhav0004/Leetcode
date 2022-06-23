class Solution {
public:
    bool validPath(int n, vector<vector<int>>& v, int source, int destination) 
    {
        if(source==destination)
            return true;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<v.size();i++)
        {
            mp[v[i][0]].push_back(v[i][1]);
            mp[v[i][1]].push_back(v[i][0]);
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(source);
        vis[source]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:mp[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    if(it==destination)
                        return true;
                    q.push(it);
                }
            }
        }
        return false;
    }
};
