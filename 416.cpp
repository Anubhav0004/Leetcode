class Solution {
public:
    bool subsetsum(vector<int> &nums,long sum,int n)
    {
        bool t[n+1][sum+1];
        for(int i=0;i<n+1;i++)
            t[i][0]=true;
        
        for(int j=1;j<sum+1;j++)
            t[0][j]=false;
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(nums[i-1]<=j)
                    t[i][j]=t[i-1][j-nums[i-1]] || t[i-1][j];
                
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][sum];
    }
    bool canPartition(vector<int>& nums) 
    {
        long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
            return false;
        sum=sum/2;
        return subsetsum(nums,sum,n);
    }
};
