class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        vector<string> v;
        map<string,int> mp;
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        vector<pair<string,int>> p(mp.begin(),mp.end());
        sort(p.begin(),p.end(),[](auto a,auto b)
             {
            if(a.second==b.second)
             {
                 return a.first<b.first;
             }
            
            return a.second>b.second;
             }
            );
        vector<string> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(p[i].first);
        }
        return ans;
    }
};
