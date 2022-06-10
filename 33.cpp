class Solution {
public:
    int find(vector<int> &nums,int start,int end,int target)
    {
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
                end=mid-1;
            else if(nums[mid]<target)
                start=mid+1;
        }
        return -1;
    }
    int getmin(vector<int> &nums)
    {
        int start=0;
        int end=nums.size()-1;
        int n=nums.size();
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int prev=(mid-1+n)%n;
            int next=(mid+1)%n;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next])
            {
                return mid;
            }
            else if(nums[mid]<=nums[end])
                end=mid-1;
            else if(nums[mid]>=nums[start])
                start=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) 
    {
        int idx=getmin(nums);
        if(nums[idx]==target)
            return idx;
        int left=find(nums,0,idx-1,target);
        int right=find(nums,idx,nums.size()-1,target);
        if(left>=0)
            return left;
        return right;
        
    }
};
