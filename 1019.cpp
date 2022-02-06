class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int> v;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        stack<int> st;
        vector<int> ans;
        // NGR
        for(int i=v.size()-1;i>=0;i--)
        {
            if(st.empty())
                ans.push_back(0);
            else if(!st.empty() && st.top()>v[i])
                ans.push_back(st.top());
            else if(!st.empty() && st.top()<=v[i])
            {
                while(!st.empty() && st.top()<=v[i])
                {
                    st.pop();
                }
                if(st.empty())
                    ans.push_back(0);
                else
                    ans.push_back(st.top());
            }
            st.push(v[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
