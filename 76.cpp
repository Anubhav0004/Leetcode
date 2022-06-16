class Solution {
public:
    string minWindow(string s, string t) 
    {
        string ans="";
        int start=0,end=0;
        unordered_map<char,int> mp;
        for(auto it:t)
        {
            mp[it]++;
        }
        int count=mp.size();
        int i=0,j=0;
        int mx=s.size()+1;
        while(j<s.size())
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    count--;
            }
            if(count>0)
            {
                j++;
            }
            else if(count==0)
            {
                while(count==0)
                {
                    int prev=mx;
                    mx=min(mx,j-i+1);
                    if(mx<prev)
                    {
                        start=i;
                    }
                    if(mp.find(s[i])!=mp.end())
                    {
                        mp[s[i]]++;
                        if(mp[s[i]]>0)
                            count++;
                        i++;
                    }
                    else
                    {
                        i++;
                    }    
                }
                j++;
            }
        }
        if(mx==s.size()+1)
            return "";
        return s.substr(start,mx);    
    }
};
