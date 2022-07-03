class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        /////////////////////////DP---100%//////////////////
        int n = nums.size();
        int peak = 1, valley = 1;
        
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1])
                peak=valley + 1;
            else if(nums[i]<nums[i-1])
                valley = peak + 1;
        }
        return max(peak, valley);
        /////////Greedy/////////////////
        if(nums.size()<2)
            return nums.size();
        int prev=nums[1]-nums[0];
        int count=prev!=0?2:1;
        int diff;
        for(int i=2;i<nums.size();i++)
        {
            diff=nums[i]-nums[i-1];
            if((diff>0 && prev<=0) || (diff<0 && prev>=0))
            {
                count++;
                prev=diff;
            }
        }
        return count;
    }
};
