class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int i=0;
        int n=matrix.size();
        int m=matrix[i].size();
        int j=m-1;
        while(i>=0 && i<n && j>=0 && j<m)
        {
            int ele=matrix[i][j];
            if(ele==target)
                return true;
            else if(ele>target)
                j--;
            else 
                i++;
        }
        return false;
    }
};
