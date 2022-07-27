class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> v;
        int n=matrix.size();
        int m=matrix[0].size();
        int top,down,left,right,dir=0;
        top=0;
        down=n-1;
        left=0;
        right=m-1;
        while(top<=down && left<=right)
        {
            if(dir==0)//going right
            {
                for(int i=left;i<=right;i++)
                    v.push_back(matrix[top][i]);
                top++;
            }
            else if(dir==1)//going down
            {
                for(int i=top;i<=down;i++)
                    v.push_back(matrix[i][right]);
                right--;
            }
            else if(dir==2)//going left
            {
                for(int i=right;i>=left;i--)
                    v.push_back(matrix[down][i]);
                down--;
            }
            else if(dir==3)//going up
            {
                for(int i=down;i>=top;i--)
                    v.push_back(matrix[i][left]);
                left++;
            }
            dir=(dir+1)%4;
        }
        return v;
    }
};
