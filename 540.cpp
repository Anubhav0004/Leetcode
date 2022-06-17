class Solution {
public:
    int singleNonDuplicate(vector<int>& v) 
    {
        if(v.size()==1)
            return v[0];
        int start=0;
        int n=v.size();
        int end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int prev=(mid-1+n)%n;
            int next=(mid+1)%n;
            if(mid%2==0)
            {
                if(v[mid]==v[next])
                    start=mid+1;
                else
                    end=mid-1;
            }
            else
            {
                if(v[mid]==v[prev])
                    start=mid+1;
                else
                    end=mid-1;
            }
        }
        return v[start];
    }
};
