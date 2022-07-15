class Solution {
public:
    bool safe(int row,int col,vector<string> &v,int n)
    {
        int duprow=row,dupcol=col;
        while(col>=0 && row>=0)
        {
            if(v[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0)
        {
            if(v[row][col]=='Q')
                return false;
            col--;
        }
        col=dupcol;
        while(row<n && col>=0)
        {
            if(v[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
     
    void solve(int col,int n,vector<string> &v,int &count)
    {
        if(col==n)
        {
            count++;
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(safe(row,col,v,n))
            {
                v[row][col]='Q';
                solve(col+1,n,v,count);
                v[row][col]='.';
            }
        }
    }
    
    int totalNQueens(int n) 
    {
        int count=0;
        vector<string> v(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            v[i]=s;
        }
        solve(0,n,v,count);
        return count;
    }
};
