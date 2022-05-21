class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
    {
        vector<int> v;
        for(int i=0;i<queries.size();i++)
        {
            int count=0;
            int x=queries[i][0];
            int y=queries[i][1];
            int z=queries[i][2];
            for(int j=0;j<points.size();j++)
            {
                int a=points[j][0];
                int b=points[j][1];
                int dist=(x-a)*(x-a)+(y-b)*(y-b);
                if(dist<=z*z)
                    count++;
            }
            v.push_back(count);
        }
        return v;
    }
};
