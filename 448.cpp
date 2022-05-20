class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            int m=abs(nums[i])-1;
            nums[m]=nums[m]>0? -nums[m]:nums[m];
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                v.push_back(i+1);
        }
        return v;
    }
};
