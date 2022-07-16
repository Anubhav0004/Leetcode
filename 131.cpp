class Solution {
public:
    bool valid(int idx,int i,string s)
    {
        while(idx<=i)
        {
            if(s[idx++]!=s[i--])
                return false;
        }
        return true;
    }
    void solve(int idx,string s,vector<string> &temp,vector<vector<string>> &v)
    {
        if(idx==s.size())
        {
            v.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();i++)
        {
            if(valid(idx,i,s))
            {
                temp.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,temp,v);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> v;
        vector<string> temp;
        solve(0,s,temp,v);
        return v;
    }
};
