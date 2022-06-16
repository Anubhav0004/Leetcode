class Solution {
public:
    int minimumCardPickup(vector<int>& v) 
    {
        unordered_map<int,int> mp;
        int mx=v.size()+1;
        for(int i=0;i<v.size();i++)
        {
            if(mp.find(v[i])!=mp.end())
            {
                mx=min(mx,i-mp[v[i]]+1);
            }
            mp[v[i]]=i;
        }
        if(mx==v.size()+1)
            return -1;
        return mx;
    }
};
