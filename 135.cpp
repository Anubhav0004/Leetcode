class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        //////////////////////optimised answer with constant space////////////
        if (ratings.size() == 0) return 0;
            int ret = 1;
            int up = 0, down = 0, peak = 0;
            for (int i = 1; i < ratings.size(); i++) {
                if (ratings[i - 1] < ratings[i]) {
                    peak = ++up;
                    down = 0;
                    ret += 1 + up;
                } else if (ratings[i - 1] == ratings[i])  {
                    peak = up = down = 0;
                    ret += 1;
                } else {
                    up = 0;
                    down++;
                    ret += 1 + down + (peak >= down ? -1 : 0);
                }
            }
        return ret;
        //////////////////////divide into left and right array add max value/////////
        int n=ratings.size();
        vector<int> left(n,1),right(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
                left[i]=left[i-1]+1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                right[i]=right[i+1]+1;
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=max(left[i],right[i]);
        }
        return sum;
    }
};
