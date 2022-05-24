class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        if(nums.size()<3)
            return v;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                int lo=i+1;
                int hi=nums.size()-1;
                int sum=0-nums[i];
                while(lo<hi)
                {
                    if(nums[lo]+nums[hi]==sum)
                    {
                        v.push_back({nums[i],nums[lo],nums[hi]});
                        while(lo<hi && nums[lo]==nums[lo+1])    
                            lo++;
                        while(lo<hi && nums[hi]==nums[hi-1])    
                            hi--;   
                        lo++;
                        hi--;
                    }
                    else if(nums[lo]+nums[hi]<sum)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        return v;
    }
};
