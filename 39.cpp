class Solution {
public:
    void solve(int i,int target,vector<int> &v,vector<vector<int>> &ans,vector<int> &temp)
    {
        if(i==v.size())
        {
            if(target==0)
                ans.push_back(temp);
            return;
        }
        if(v[i]<=target)
        {
            temp.push_back(v[i]);
            solve(i,target-v[i],v,ans,temp);
            temp.pop_back();
        }
        solve(i+1,target,v,ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& v, int target) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,target,v,ans,temp);
        return ans;
    }
};
