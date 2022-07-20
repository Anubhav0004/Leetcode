class Solution {/////////1 take first index////////2 take last index////apply same logic/////////100%////////////////////
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int prev2=0,prev=nums[0],curr;
        vector<int> dp(n,-1);
        for(int i=1;i<n-1;i++)
        {
            int left=nums[i]+prev2;
            int right=prev;
            curr=max(left,right);
            prev2=prev;
            prev=curr;
        }
        int ans1=prev;
        prev=nums[1],prev2=0;
        for(int i=2;i<n;i++)
        {
            int left=nums[i]+prev2;
            int right=prev;
            curr=max(left,right);
            prev2=prev;
            prev=curr;
        }
        return max(prev,ans1);
    }
};
