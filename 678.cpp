class Solution {////////////////////////100% solution///////////////////
public:
    bool checkValidString(string s) 
    {
        // int count=0;
        stack<int> st;
        stack<int> star;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
                star.push(i);
            else if(s[i]=='(')
                st.push(i);
            else if(s[i]==')')
            {
                if(!st.empty())
                    st.pop();
                else if(st.empty())
                {
                    if(!star.empty())
                        star.pop();
                    else
                        return false;
                }
            }
        }
        while(!st.empty() && !star.empty())
        {
            if(star.top()>st.top())
            {
                st.pop();
                star.pop();
            }
            else
                return false;
        }
        return st.empty();
    }
};
