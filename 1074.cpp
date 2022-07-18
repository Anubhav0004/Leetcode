class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int n=matrix.size(),m=matrix[0].size(),ans=0;
        //intitalize all with prefix sum
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        unordered_map<int,int> mp;
        for(int start=0;start<m;start++)
        {
            for(int end=start;end<m;end++)
            {
                mp.clear();
                mp[0]++;
                int currsum=0;
                for(int i=0;i<n;i++)
                {
                    int curr=matrix[i][end];
                    if(start>0)
                        curr-=matrix[i][start-1];
                    currsum+=curr;
                    ans+=mp[currsum-target];
                    mp[currsum]++;
                }
            }
        }
        return ans;
    }
};
