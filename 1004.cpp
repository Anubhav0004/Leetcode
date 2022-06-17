class Solution {
public:
    int longestOnes(vector<int>& v, int k) 
    {
        int i=0;
        int mx=0;
        int count=0;
        for(int j=0;j<v.size();j++)
        {
            if(v[j]==0)
                count++;
            while(count>k)
            {
                if(v[i]==0)
                    count--;
                i++;
            }
            mx=max(mx,j-i+1);
        }
        return mx;
    }
};
