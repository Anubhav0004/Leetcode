class Solution {
public:
    int minInsertions(string a) 
    {
        int n=a.size(),count;
        string b="";
        for(int i=n-1;i>=0;i--)
        {
            b+=a[i];
        }
        int t[n+1][n+1];
        for(int i=0;i<n+1;i++)
            t[i][0]=0;
        for(int j=0;j<n+1;j++)
            t[0][j]=0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(a[i-1]==b[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        count=t[n][n];
        
        return n-count;
    }
};
