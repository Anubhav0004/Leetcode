class Solution {
public:
    int minSubArrayLen(int target, vector<int>& v) 
    {
        int k=target;
        int r=v.size()+1;
        int i=0,j=0;
        int sum=0;
        while(j<v.size())
        {
            sum+=v[j];
            if(sum<k)
                j++;
            else if(sum==k)
            {
                r=min(r,j-i+1);
                j++;
            }
            else if(sum>k)
            {
                
                while(sum>k)
                {
                    r=min(r,j-i+1);
                    sum=sum-v[i];
                    i++;
                }
                if(sum==k)
                {
                    r=min(r,j-i+1);
                }
                j++;
            }
        }
        if(r==v.size()+1)
            return 0;
        return r;
    }
};
