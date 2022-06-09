class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> v;
        int start=0;
        int end=numbers.size()-1;
        while(true)
        {
            int sum=numbers[start]+numbers[end];
            if(sum==target)
            {
                v.push_back(start+1);
                v.push_back(end+1);
                return v;
            }
            else if(sum<target)
                start++;
            else 
                end--;
        }
        return v;
    }
};
