class Solution {
public:
    bool search(vector<int>& v, int k) 
    {
        int start=0;
        int end=v.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(v[mid]==k)
                return true;
            else if(v[mid]==v[start] && v[mid]==v[end])
            {
                start++;
                end--;
            }
            else if(v[mid]>=v[start])
            {
                if(v[start]<=k && v[mid]>k)
                    end=mid-1;
                else
                    start=mid+1;
            }
            else 
            {
                if(v[mid]<k && v[end]>=k)
                {
                    start=mid+1;
                }
                else
                    end=mid-1;
            }
        }
        return false;
    }
};




class Solution { /////not optimised
public:
    bool search(vector<int>& nums, int target) 
    {
        for(auto it:nums)
        {
            if(it==target)
                return true;
        }
        return false;
    }
};
