class Solution {
public:
    void swap(vector<int> &v,int a,int b)
    {
        int temp=v[a];
        v[a]=v[b];
        v[b]=temp;
    }
    void reverse(vector<int> &v,int start,int end)
    {
        while(start<end)
        {
            swap(v,start,end);
            start++;
            end--;
        }
    }
    void nextPermutation(vector<int>& nums) 
    {
        if(nums.size()<2)
            return;
        int n=nums.size();
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1])
            i--;
        if(i>=0)
        {
            int j=n-1;
            while(nums[j]<=nums[i])
                j--;
            swap(nums,i,j);
        }
        reverse(nums,i+1,n-1);
    }
};
