class Solution {///////////////recursion----->gives TLE///////////////////
public:
    int longestCommonSubsequence(string text1, string text2) 
    {//////////////////////optimum ----DP /////////////////////////
        int n=text1.size();
        int m=text2.size();
        // int count=0;
        int t[n+1][m+1];
        ///initialization
        for(int i=0;i<n+1;i++)
        {
            t[i][0]=0;
        }
        for(int j=0;j<m+1;j++)
        {
            t[0][j]=0;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(text1[i-1]==text2[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
        }
        return t[n][m];
    }
};

/////////////////memoization approach----->works fine ////////////////////////////////////
int t[1001][1001];
    int lcs(string &text1,string &text2,int n,int m)
    {
        if(n==0||m==0)
            return 0;
        if(t[n][m]!=-1)
            return t[n][m];
        if(text1[n-1]==text2[m-1])
        {
            return t[n][m]=1+lcs(text1,text2,n-1,m-1);
        }
        else
            return t[n][m]=max(lcs(text1,text2,n-1,m),lcs(text1,text2,n,m-1));
    }
    
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n=text1.size();
        int m=text2.size();
        int count=0;
        memset(t,-1,sizeof(t));
        count=lcs(text1,text2,n,m);
        return count;
    }
};
///////////////Recursive Approach----------->TLE/////////////////////////
int lcs(string text1,string text2,int n,int m)
    {
        if(n==0||m==0)
            return 0;
        if(text1[n-1]==text2[m-1])
        {
            return 1+lcs(text1,text2,n-1,m-1);
        }
        else
            return max(lcs(text1,text2,n-1,m),lcs(text1,text2,n,m-1));
    }
    
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n=text1.size();
        int m=text2.size();
        int count=0;
        count=lcs(text1,text2,n,m);
        return count;
    }
