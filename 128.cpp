class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> s;
        for(auto it:nums)
        {
            s.insert(it);
        }
        int ans=0;
        for(auto it:nums)
        {
            if(s.find(it-1)!=s.end())
                continue;
            else
            {
                int count=0;
                int current=it;
                while(s.find(current)!=s.end())
                {
                    count++;
                    current++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};
