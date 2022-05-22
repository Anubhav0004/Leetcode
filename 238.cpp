class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> right(nums.size());
        int pro=1;
        vector<int> v;
        pro=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            pro=pro*nums[i];
            right[i]=pro;
        }
        pro=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            int res=pro*right[i+1];
            v.push_back(res);
            pro*=nums[i];
        }
        v.push_back(pro);
        return v;
    }
};
