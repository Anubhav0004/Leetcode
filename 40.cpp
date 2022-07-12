class Solution {
public:
    void solve(int idx,int target,vector<int> &v,vector<int> &temp,vector<vector<int>> &ans)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<v.size();i++)
        {
            if(i>idx && v[i]==v[i-1]) continue;
            if(v[i]>target) break;
            temp.push_back(v[i]);
            solve(i+1,target-v[i],v,temp,ans);
            temp.pop_back();
        }
        // solve(i+1,target,v,temp,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int target) 
    {
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,target,v,temp,ans);
        return ans;
    }
};
