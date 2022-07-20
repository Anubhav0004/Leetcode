class Solution {///////////////////////my sol doesn't consider the case for duplicate strings///// 
public:
    bool solve(string &a,string b)
    {
        if(b.size()>a.size())
            return false;
        int s1=0,s2=0,count=0;
        while(s1<a.size() && s2<b.size())
        {
            if(a[s1]==b[s2])
                s2++;
            s1++;
        }
        return s2==b.size();
    }
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        int count=0;
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        for(auto it:mp)
        {
            if(solve(s,it.first))
                count+=it.second;
        }
        return count;
    }
};
