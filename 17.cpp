class Solution {///////////////hashmap used here is array of string//////////
public:
    void solve(string &digits,string op,int idx,string mp[],vector<string> &ans)
    {
        if(idx>=digits.size())
        {
            ans.push_back(op);
            return;
        }
        int num=digits[idx]-'0';
        string val=mp[num];
        for(int i=0;i<val.size();i++)
        {
            op.push_back(val[i]);
            solve(digits,op,idx+1,mp,ans);
            op.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        vector<string>ans;
        if(digits.length()==0)
            return ans;
        string op;
        int idx=0;
        string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,op,idx,mp,ans);
        return ans;
    }
};
