class Solution {/////////////////iska answer aise hi karna hai/////////////
public:
    int t[2001][2001];
    bool ispalindrome(string &s,int i,int j)
    {
        // if(i>=j)
        //     return true;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s,int i,int j)
    {
        if(i>=j)
            return 0;
        if(t[i][j]!=-1)
            return t[i][j];
        if(ispalindrome(s,i,j))
            return t[i][j]=0;
        int mn=INT_MAX;
        for(int k=i;k<j;k++)
        {
            if(ispalindrome(s,i,k))
            {
                mn = min(mn, 1+ solve(s,k+1,j));
            }
            // int temp=1+solve(s,i,k)+solve(s,k+1,j);
            // if(mn>temp)
            //     mn=temp;
        }
        return t[i][j]=mn;
    }
    int minCut(string s) 
    {
        memset(t,-1,sizeof(t));
        int n=s.length();
        return solve(s,0,n-1);
    }
};
