class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        // map<char,int> mp;
        // for(int i=0;i<s.length();i++)
        // {
        //     mp[s[i]]++;
        // }
        // string out="";
        // vector<char> v;
        // for(auto it=mp.begin();it!=mp.end();it++)
        // {
        //     v.push_back(it->first);
        // }
        // // sort(v.begin(),v.end());
        // for(int i=0;i<v.size();i++)
        // {
        //     out+=v[i];
        // }
        // return out;
        
        // cnt for storing frequency of characters
        // vis for marking visited characters
        vector<int> cnt(26,0)  , vis(26,0);
        
        string res = "";
        int n = s.size();
        
        for(int i = 0; i<n; ++i)
            cnt[s[i] - 'a']++;
        
        for(int i = 0; i<n; ++i)
        {
            // decrease cnt of current character
            cnt[s[i] - 'a']--;
            
            // If character is not already
            // in answer
            if(!vis[s[i]- 'a'])
            {
                // Last character > s[i]
                // and its count > 0
                while(res.size() > 0 && res.back() > s[i] && cnt[res.back() - 'a'] > 0)
                {
                    // marking letter visited
                    vis[res.back() - 'a'] = 0;
                    res.pop_back();
                }
                
                // Add s[i] in res and
                // mark it visited
                res += s[i];
                vis[s[i] - 'a'] = 1;
            }
        }
        // return resultant string
        return res;
    }
};
