class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int start=0,end=nums.size()-1;
        int ans;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]<target)
                start=mid+1;
            else if(nums[mid]==target)
                return mid;
            else
                end=mid-1;
        }
        return start;
    }
};
