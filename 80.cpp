class Solution { /////////appear atmost k times in sorted array//////////////////
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int k=2;
        int n=nums.size();
        if (n <= k) return n;
        int i = 1, j = 1;
        int cnt = 1;
        while (j < n) 
        {
            if (nums[j] != nums[j-1]) 
            {
                cnt = 1;
                nums[i++] = nums[j];
            }
            else 
            {
                if (cnt < k) 
                {
                    nums[i++] = nums[j];
                    cnt++;
                }
            }
            j++;
        }
        return i;
    }
};
