class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        vector<int> v;
        priority_queue<int,vector<int>,greater<int>> hp;
        for(int i=0;i<nums.size();i++)
        {
            hp.push(nums[i]);
        }
        while(!hp.empty())
        {
            v.push_back(hp.top());
            hp.pop();
        }
        return v;
    }
};
