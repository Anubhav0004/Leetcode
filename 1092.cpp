class Solution {
public:
    string shortestCommonSupersequence(string x, string y) 
    {
        int n=x.size();
        int m=y.size();
        int t[n+1][m+1];
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
                if(x[i-1]==y[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                }
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        int i=n,j=m;
        string s="";
        while(i>0 && j>0)
        {
            if(x[i-1]==y[j-1])
            {
                s.push_back(x[i-1]);
                i--;
                j--;
            }
            else
            {
                if(t[i][j-1]>t[i-1][j])
                {
                    s.push_back(y[j-1]);
                    j--;
                }
                else 
                {
                    s.push_back(x[i-1]);
                    i--;
                }
            }
        }
        while(i>0)
        {
            s.push_back(x[i-1]);
            i--;
        }
        while(j>0)
        {
            s.push_back(y[j-1]);
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
