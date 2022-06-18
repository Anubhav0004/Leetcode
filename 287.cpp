class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        //binary search
        int left = 1, right = nums.size() - 1;
        while(left < right) 
        {
            int mid = left + (right - left) / 2;    
            // count the number of elements smaller/ equal than middle element
            int c = 0;
            for(auto el: nums)
                if(el <= mid)
                    ++c;
            if(c > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
        //O(n) faser
//         for(int i=0;i<nums.size();i++)
//         {
//             int idx=abs(nums[i])-1;
            
//             nums[idx]=nums[idx]*-1;
//             if(nums[idx]>0)
//                 return abs(nums[i]);
//         }
//         return 0;
    }
};
