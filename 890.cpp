class Solution {
public:
    bool ismatching(string word,string pattern)
    {
        unordered_map<char,char> mp;
        unordered_set<char> s;
        for(int i=0;i<word.size();i++)
        {
            if(mp.find(pattern[i])!=mp.end())
            {
                if(mp[pattern[i]]!=word[i])
                    return false;
            }
            else
            {
                if(s.find(word[i])!=s.end())
                    return false;
                mp[pattern[i]]=word[i];
                s.insert(word[i]);
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> v;
        vector<int> v1;
        for(auto it:words)
        {
            if(ismatching(it,pattern))
                v.push_back(it);
        }
        return v; 
    }
};
