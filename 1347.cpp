//////////////////////////////////////////////////OPTIMISED APPROACH///////////////////////////////////////////////////////
class Solution {
public:
    int minSteps(string s, string t) 
    {
        int count=0;
        unordered_map<char,int> mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        for(auto it:t)
        {
            mp[it]--;
        }
        for(auto it:mp)
        {
            if(it.second<0)
                count+=it.second;
        }
        return abs(count);
    }
};

////////////////////////////////////MINE////////////////////////////////////////////////////////


class Solution {
public:
    int minSteps(string s, string t) 
    {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        int add=0,sub=0;
        for(int i=0;i<s.size();i++)
        {
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        for(auto it:mp1)
        {
            if(mp2.find(it.first)!=mp2.end())
            {
                int diff=mp2[it.first]-it.second;
                if(diff>0)
                    sub+=diff;
                else if(diff<0)
                    add+=abs(diff);
            }
            else
            {
                add+=it.second;
            }
        }
        for(auto it:mp2)
        {
            if(mp1.find(it.first)==mp1.end())
                sub+=it.second;
        }
        if(sub==add)
        return sub;
        return abs(sub-add);
    }
};
