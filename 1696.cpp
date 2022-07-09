class Solution {///////////////sliding window////////////////
public:
    int maxResult(vector<int>& nums, int k) 
    {
        queue<int> q;
        q.push(0);
        for(int i=1;i<nums.size();i++)
        {
           if(q.front()+k<i)
               q.pop();
            nums[i]+=nums[q.front()];
            while(!q.empty() && nums[q.front()]<=nums[i])
                q.pop();
            q.push(i);
        }
        return nums.back();
    }
};
