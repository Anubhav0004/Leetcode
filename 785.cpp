class Solution {
public:
    bool check(int node,vector<int> &color,vector<vector<int>> v)
    {
        color[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:v[node])
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& v) 
    {
        int n=v.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!check(i,color,v))
                    return false;
            }
        }
        return true;
    }
};
