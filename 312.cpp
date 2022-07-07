class Solution {
public:
    int t[303][303];
    int solve(vector<int> &nums,int i,int j)
    {
        if(i>=j)
            return t[i][j]=0;
        if(t[i][j]!=-1)
            return t[i][j];
        int mx=0;
        for(int k=i;k<j;k++)
        {
            int temp=solve(nums,i,k)+solve(nums,k+1,j)+(nums[i-1]*nums[k]*nums[j]);
            if(mx<temp)
                mx=temp;
        }
        return t[i][j]=mx;
    }
    int maxCoins(vector<int>& nums) 
    {
        /////////only catch is we have to insert 1 at begining and end
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        memset(t,-1,sizeof(t));
        int n=nums.size();
        return solve(nums,1,n-1);
    }
};
