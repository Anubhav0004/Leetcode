class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        unordered_map<char,int> mp;
        vector<int> v;
    for(auto it:p)
    {
        mp[it]++;
    }
    int count=mp.size();
    int res=0;
    int k=p.size();
    for(int i=0;i<k;i++)
    {
        if(mp.find(s[i])!=mp.end())
        {
            mp[s[i]]--;
            if(mp[s[i]]==0)
            {
                count--;
            }
        }
    }
    if(count==0)
        v.push_back(0);
    for(int i=k;i<s.size();i++)
    {
        if(mp.find(s[i-k])!=mp.end())
        {
            if(mp[s[i-k]]==0)
            {
                count++;
            }
            mp[s[i-k]]++;
        }
        if(mp.find(s[i])!=mp.end())
        {
            mp[s[i]]--;
            if(mp[s[i]]==0)
            {
                count--;
            }
        }
        if(count==0)
        {
            v.push_back(i-k+1);
        }
    }
        return v;
    }
};
