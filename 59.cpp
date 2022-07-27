class Solution {/////////////// 100%solution ///////////////
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> v(n,vector<int>(n,0));
        int ele=1,dir=0;
        int top,down,left,right;
        top=0;
        down=n-1;
        left=0;
        right=n-1;
        while(left<=right && top<=down)
        {
            if(dir==0)
            {
                for(int i=left;i<=right;i++)
                {
                    v[top][i]=ele;
                    ele++;
                }
                top++;
            }
            else if(dir==1)
            {
                for(int i=top;i<=down;i++)
                {
                    v[i][right]=ele;
                    ele++;
                }
                right--;
            }
            else if(dir==2)
            {
                for(int i=right;i>=left;i--)
                {
                    v[down][i]=ele;
                    ele++;
                }
                down--;
            }
            else if(dir==3)
            {
                for(int i=down;i>=top;i--)
                {
                    v[i][left]=ele;
                    ele++;
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return v;
    }
};
