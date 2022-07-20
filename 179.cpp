class Solution {////////////////100%solution////////////////
public:
    string largestNumber(vector<int>& nums) 
    {
        string s="";
        vector<string> v;
        for(auto it:nums)
        {
            v.push_back(to_string(it));
        }
        sort(v.begin(),v.end(),[](string &a,string &b) { return a+b>b+a; } );
        for(auto it:v)
            s.append(it);
        while(s[0]=='0' && s.size()>1)
            s.erase(0,1);
        return s;
    }
};
