class Solution {
public:
    string frequencySort(string s) 
    {
        string op;
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> hp;
        
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            hp.push({it->second,it->first});
        }
        while(hp.size()!=0)
        {
            int count=hp.top().first;
            while(count!=0)
            {
                op+=hp.top().second;
                count--;
            }
            hp.pop();
        }
        return op;
    }
};
