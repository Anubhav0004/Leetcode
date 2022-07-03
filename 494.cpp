class Solution {
public:
    int numberofsubsets(int n,vector<int>& nums,int sum)
    {
        int t[n+1][sum+1];
        for(int i=0;i<n+1;i++)
        {
            t[i][0]=1;
        }
        for(int j=1;j<sum+1;j++)
        {
            t[0][j]=0;
        }
        // t[0][0]=1;
        for(int i=1;i<n+1;i++)
        {
           for(int j=0;j<sum+1;j++)
            {
                if(nums[i-1]<=j)
                    t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            } 
        }
        return t[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        target=abs(target);
        int sum=0;
        for(auto it:nums)
        {
            sum+=it;
        }
        if(sum<target || (sum+target)%2!=0)
            return 0;
        int n=nums.size();
        sum=(target+sum)/2;
        return numberofsubsets(n,nums,sum);
    }
};
