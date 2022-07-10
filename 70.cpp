class Solution {/////////////////similar to fibonacci starting from 1st index////////////////////
public:
    int climbStairs(int n) 
    {
        if(n<=2)
            return n;
        int prev=2,prev2=1,curr;
        for(int i=3;i<=n;i++)
        {
            curr=prev+prev2;
            prev2=prev;
            prev=curr;;
        }
        return prev;
    }
};
