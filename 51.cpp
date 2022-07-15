class Solution {
public:
    bool safe(int row,int col,vector<string> &v,int n)
    {
        int dupcol=col,duprow=row;
        //for upper diagonal
        while(row>=0 && col>=0)
        {
            if(v[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        row=duprow;
        col=dupcol;
        //for same column
        while(col>=0)
        {
            if(v[row][col]=='Q')
                return false;
            col--;
        }
        col=dupcol;
        //for lower diagonal
        while(col>=0 && row<n)
        {
            if(v[row][col]=='Q')
                return false;
            col--;
            row++;
        }
        return true;
    }
    
    void solve(int col,int n,vector<string> &v,vector<vector<string>> &ans)
    {
        if(col==n)
        {
            ans.push_back(v);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(safe(row,col,v,n))
            {
                v[row][col]='Q';
                solve(col+1,n,v,ans);
                v[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> v(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            v[i]=s;
        }
        solve(0,n,v,ans);
        return ans;
    }
};
