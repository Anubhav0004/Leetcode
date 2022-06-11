class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=m-1;
        int j=0;
        while(i>=0 && i<m && j>=0 && j<n)
        {
            int ele=matrix[i][j];
            if(ele==target)
                return true;
            else if(ele>target)
                i--;
            else 
                j++;
        }
        return false;
    }
};
