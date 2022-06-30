class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        ////////////////////optimised/////////////////////////
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int sum=0;
        while(i<j)
        {
            sum+=nums[j]-nums[i];
            i++;
            j--;
        }
        return sum;
        
        //////////////median lekar difference nikal lo//////////////////////////
        int n=nums.size();
        int mid;
        sort(nums.begin(),nums.end());
        if(n%2==0)
            mid=(((n/2)-1)+(n/2))/2;
        else
            mid=n/2;
        int median=nums[mid];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=abs(nums[i]-median);
        }
        return sum;
    }
};
