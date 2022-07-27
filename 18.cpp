class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> v;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            long long t1=target-nums[i];
            for(int j=i+1;j<n;j++)
            {
                long long t2=t1-nums[j];
                int left=j+1,right=n-1;
                while(left<right)
                {
                    if(nums[left]+nums[right]==t2)
                    {
                        vector<int> quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[left];
                        quad[3]=nums[right];
                        v.push_back(quad);
                        //duplicates for num3
                        while(left<right && nums[left]==quad[2]) left++;
                        // dup for num4
                        while(left<right && nums[right]==quad[3]) right--;
                    }
                    else if(nums[left]+nums[right]<t2)
                        left++;
                    else
                        right--;
                }
                //dup in j
                while(j+1<n && nums[j+1]==nums[j]) j++;
            }
            // dup in i
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return v;
    }
};
