class Solution {
public:
    // int solve(int idx,vector<int> &nums,vector<int> &dp)
    // {
    //     if(idx==0)
    //         return nums[0];
    //     if(idx<0)
    //         return 0;
    //     if(dp[idx]!=-1)
    //         return dp[idx];
    //     int left=nums[idx]+solve(idx-2,nums,dp);
    //     int right=solve(idx-1,nums,dp);
    //     return dp[idx]=max(left,right);
    // }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        // vector<int> dp(n,-1);
        // return solve(nums.size()-1,nums,dp);
        // dp[0]=nums[0];
        // int neg=0;
        int prev=nums[0],prev2=0,curr=0;
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notpick=prev;
            curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
