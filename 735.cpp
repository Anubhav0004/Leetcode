class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) 
    {
        vector<int> res;
        stack<int> s;
        int n = ast.size();
        for(int i = 0; i < n; i++) 
        {
            if(ast[i] > 0 || s.empty()) 
            {
                s.push(ast[i]);
            }
            else {
                while(!s.empty() and s.top() > 0 and s.top() < abs(ast[i])) 
                {
                    s.pop();
                }
                if(!s.empty() and s.top() == abs(ast[i])) 
                {
                    s.pop();
                }
                else {
                    if(s.empty() || s.top() < 0) 
                    {
                        s.push(ast[i]);
                    }
                }
            }
        }
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
