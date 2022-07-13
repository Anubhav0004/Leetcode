class Solution {/////////////////done myself///////////////////////
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int cnt=1;
        int i=1;
        int idx=0;
        while(i!=nums.size())
        {
            if(nums[idx]<nums[i])
            {
                idx++;
                cnt++;
                nums[idx]=nums[i];
            }
            i++;
        }
        return cnt;
    }
};
