class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        
        // if(s.length()%2!=0) return false;
        
        for(int i=0;i<s.length();i++)
        {
            char a=s[i];
            switch(a)
            {
                case '{':
                    st.push(a);
                    break;
                case '[':
                    st.push(a);
                    break;
                case '(':
                    st.push(a);
                    break;
                    
                case '}':
                    if(!st.empty() && st.top()=='{' )
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                    
                case ']':
                    if(!st.empty() && st.top()=='[')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case ')':
                    if(!st.empty() && st.top()=='(')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
            }        
        }
        if(st.empty())
            return true;
        return false;
    }
};
