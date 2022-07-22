class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int i=0,count=0,ans=0;
        while(i<nums.size())
        {
            if(nums[i]==0)
                i++;
            else
            {
                while(i<nums.size() && nums[i]==1)
                {
                    count++;
                    i++;
                }
            }
            ans=max(ans,count);
            count=0;
        }
        return ans;
    }
};
