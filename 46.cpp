class Solution {
public:////////////////better appraoch---faster/////////////////
    void solve(vector<int> &nums,vector<int> &temp,int freq[],vector<vector<int>> &ans)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!freq[i])
            {
                temp.push_back(nums[i]);
                freq[i]=1;
                solve(nums,temp,freq,ans);
                freq[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int freq[nums.size()];
        memset(freq,0,sizeof(freq));
        solve(nums,temp,freq,ans);
        return ans;
    }
};

///////////space optimised//////////////////////////////
/*void solve(int idx,vector<int> &nums,vector<vector<int>> &ans)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[idx],nums[i]);
            solve(idx+1,nums,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        // vector<int> temp;
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return ans;
    }*/
