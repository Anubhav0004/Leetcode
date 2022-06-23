class Solution {
public:
    void findtopo(int node,vector<int> &vis2,stack<int> &st,unordered_map<int,vector<int>> &mp)
    {
        vis2[node]=1;
        for(auto it:mp[node])
        {
            if(!vis2[it])
                findtopo(it,vis2,st,mp);
        }
        st.push(node);
    }
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
    vector<int> findOrder(int n, vector<vector<int>>& v) 
    {
        unordered_map<int,vector<int>> mp;
        vector<int> topo;
        vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
        for(int i=0;i<v.size();i++)
        {
            mp[v[i][1]].push_back(v[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(checkcycle(i,vis,dfsvis,mp))
                    return topo;
            }
        }
        stack<int> st;
        vector<int> vis2(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis2[i])
            {
                findtopo(i,vis2,st,mp);
            }
        }
        while(!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};
