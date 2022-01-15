class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<int> v;
        priority_queue<pair<int,int>> hp;
        unordered_map<int,int> mp;
        int count;
        for(int i=0;i<mat.size();i++)
        {
            count=0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                {
                    count++;
                }
            }
            mp[i]=count;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            hp.push({it->second,it->first});
            if(hp.size()>k)
            {
                hp.pop();
            }
        }
        while(!hp.empty())
        {
            v.push_back(hp.top().second);
            hp.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
