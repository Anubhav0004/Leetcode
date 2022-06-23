class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        ///////////////optimum///////////////
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
        
        //////////////////alternate///////////////////////////////
        int n=edges.size()+1;
        vector<int> count(n+1,0);
        for(auto it:edges)
        {
            count[it[0]]++;
            count[it[1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(count[i]==n-1)
                return i;
        }
        
        ///////////////my approach////////////////
        unordered_map<int,vector<int>> mp;
        int n=edges.size();
        for(int i=0;i<n;i++)
        {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        int s=mp.size();
        for(auto it:mp)
        {
            int size=it.second.size();
            if(size==s-1)
                return it.first;
        }
        return 0;
    }
};
