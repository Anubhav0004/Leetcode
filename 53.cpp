class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        // if(nums.size()==1)
        //     return nums[0];
        int mx=INT_MIN,sum=0;
        for(auto it:nums)
        {
            sum+=it;
            if(sum>mx)
                mx=sum;
            if(sum<0)
                sum=0;
        }
        return mx;
    }
};
