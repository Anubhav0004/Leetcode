////////////////////////////////////////////////APPROACH 1///////////////////////////////////////////////
int find(int val,vector<int> nums2)
    {
        for(int i=0;i<nums2.size();i++)
        {
            if(val==nums2[i])
                return i;
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack<int> st;
        vector<int> v;
        vector<int> ans;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(st.empty())
                v.push_back(-1);
            else if(!st.empty() && st.top()>nums2[i])
                v.push_back(st.top());
            else if(!st.empty() && st.top()<=nums2[i])
            {
                while(!st.empty() && st.top()<=nums2[i])
                {
                    st.pop();
                }
                if(st.empty())
                    v.push_back(-1);
                else
                    v.push_back(st.top());
            }
            st.push(nums2[i]);
        }
        reverse(v.begin(),v.end());
       
        for(int i=0;i<nums1.size();i++)
        {
            int idx=find(nums1[i],nums2);
            if(idx==-1)
                ans.push_back(-1);
            else
            ans.push_back(v[idx]);
        }
        return ans;
    }

/////////////////////////////////////////////////////////////////////APPROACH 2//////////////////////////////////////////////////////////////////
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int> mp;
        stack<int> st;
        vector<int> v;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(st.empty())
                mp.insert({nums2[i],-1});
            else if(!st.empty() && st.top()>nums2[i])
                mp.insert({nums2[i],st.top()});
            else if(!st.empty() && st.top()<=nums2[i])
            {
                while(!st.empty() && st.top()<=nums2[i])
                {
                    st.pop();
                }
                if(st.empty())
                    mp.insert({nums2[i],-1});
                else
                    mp.insert({nums2[i],st.top()});
            }
            st.push(nums2[i]);
        }
        // for(auto it=mp.begin();it!=mp.end();it++)
        // {
        //     cout<<it->first<<" "<<it->second<<endl;
        // }
        for(int i=0;i<nums1.size();i++)
        {
            auto it=mp.find(nums1[i]);
            if(it==mp.end())
                v.push_back(-1);
            else
                v.push_back(it->second);
        }
        return v;
    }
