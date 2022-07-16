class Solution {/////////////////////////////////////////////////100%///////////////////////////////////////////////////////////
public:
    int mod=1000000007;
    int t[51][51][51];
    int solve(int m,int n,int maxMove,int i,int j)
    {
        if(i<0 || j<0 || i>=m || j>=n)
            return 1;
        if(maxMove<=0)
            return 0;
        if(t[i][j][maxMove]!=-1)
            return t[i][j][maxMove];
        long res=0;
        res+=solve(m,n,maxMove-1,i,j+1);
        res+=solve(m,n,maxMove-1,i,j-1);
        res+=solve(m,n,maxMove-1,i+1,j);
        res+=solve(m,n,maxMove-1,i-1,j);
        return t[i][j][maxMove]=res%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        memset(t,-1,sizeof(t));
        return solve(m,n,maxMove,startRow,startColumn)%mod;   
    }
};
