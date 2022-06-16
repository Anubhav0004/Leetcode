class Solution { //////////////////////////using hash set (optimal) ///////////////////////////////////
public:
    int maximumUniqueSubarray(vector<int>& s) 
    {
        unordered_set<int> mp;
        int i=0,j=0;
        long sum=0,res=0;
        while(j<s.size())
        {
            while(mp.find(s[j])!=mp.end())
            {
                mp.erase(s[i]);
                sum-=s[i];
                i++;
            }
            mp.insert(s[j]);
            sum+=s[j];
            res=max(sum,res);
            j++;
        }
        return res;
    }
};

class Solution { /////////////////////////////////////my approach/////////////////////////////////////
public:
    int maximumUniqueSubarray(vector<int>& s) 
    {
        unordered_map<int,int> mp;
        int i=0,j=0;
        long sum=0;
        while(j<s.size())
        {
            mp[s[j]]++;
            if(mp.size()<j-i+1)
            {
                while(mp.size()<j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
            }
            else if(mp.size()==j-i+1)
            {
                long sm=0;
                for(auto it:mp)
                {
                    sm+=it.first*it.second;
                }
                sum=max(sm,sum);
            }
            j++;
        }
        return sum;
    }
};
