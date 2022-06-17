class Solution {
public:
    int totalFruit(vector<int>& v) 
    {
        int i=0,j=0;
        int mx=1;
        int k=2;
        unordered_map<int,int> mp;
        while(j<v.size())
        {
            mp[v[j]]++;
            if(mp.size()<k)
                j++;
            else if(mp.size()==k)
            {
                mx=max(mx,j-i+1);
                j++;
            }
            else if(mp.size()>k)
            {
                while(mp.size()>k)
                {
                    if(mp.find(v[i])!=mp.end())
                        mp[v[i]]--;
                    if(mp[v[i]]==0)
                        mp.erase(v[i]);
                    i++;
                }
                j++;
            }
        }
        if(mp.size()==1)
        {
            for(auto it:mp)
                return it.second;
        }
        return mx;
    }
};
