class Solution {
public:
    int t[51][51];
    int solve(vector<int> &values,int i,int j)
    {
        if(i>=j)
            return t[i][j]=0;
        if(t[i][j]!=-1)
            return t[i][j];
        int mn=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp=solve(values,i,k)+solve(values,k+1,j)+(values[i-1]*values[k]*values[j]);
            if(temp<mn)
                mn=temp;
        }
        return t[i][j]=mn;
    }
    int minScoreTriangulation(vector<int>& values) 
    {
        memset(t,-1,sizeof(t));
        int n=values.size();
        return solve(values,1,n-1);
    }
};
