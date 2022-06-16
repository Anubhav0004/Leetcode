class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) 
    {
        unordered_map<int,int> mp;
        int i=0,j=0;
        int diff=-1;
        while(j<v.size())
        {
            if(mp.find(v[j])!=mp.end())
            {
                diff=j-mp[v[j]];
            }
            if(diff>0 && diff<=k)
                return true;
            else if(diff>k)
            {
                mp.erase(mp[v[i]]);
                i++;
            }
            mp[v[j]]=j;
            j++;
        }
        return false;
    }
};
