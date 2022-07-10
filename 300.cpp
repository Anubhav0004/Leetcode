class Solution {
public:
    int t[2501][2501];
    int solve(vector<int> &nums,int idx,int prev,int size)
    {
        if(idx==size)
            return 0;
        if(t[idx][prev+1]!=-1)
            return t[idx][prev+1];
        int len=0+solve(nums,idx+1,prev,size);
        if(prev==-1 || nums[idx]>nums[prev])
        {
            len=max(len,1+solve(nums,idx+1,idx,size));
        }
        return t[idx][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        memset(t,-1,sizeof(t));
        int n=nums.size();
        return solve(nums,0,-1,n);
    }
};
