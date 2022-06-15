class Solution {  /////////////////////////hash map best approach///////////////////////
public:
    int lengthOfLongestSubstring(string s) 
    {
        int i=0,j=0;
        int mx=0;
        unordered_map<char,int> mp;
        int count=0;
        while(j<s.size())
        {
            mp[s[j]]++;
            if(mp.size()<j-i+1)
            {
                while(mp.size()<j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
            else if(mp.size()==j-i+1)
            {
                int size=mp.size();
                mx=max(mx,size);
                j++;
            }
        }
        return mx;
    }
};






class Solution {    /////////////////////////////hash map////////////////////////////////////////
public:
    int lengthOfLongestSubstring(string s) 
    {
        int i=0,j=0;
        int mx=0;
        unordered_map<char,int> mp;
        int count=0;
        while(j<s.size())
        {
            if(mp.find(s[j])==mp.end())
            {
                mp[s[j]]++;
                j++;
                int size=mp.size();
                mx=max(mx,size);
            }
            else if(mp[s[j]]>0)
            {
                while(mp[s[j]]>0)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
                mp[s[j]]++;
                j++;
            }
        }
        return mx;
    }
};


class Solution {    //////////////////////////////////////////using set//////////////////////////////
public:
    int lengthOfLongestSubstring(string s) 
    {
        int i=0,j=0;
        int mx=0;
        unordered_set<char> st;
        int count=0;
        // string res="";
        while(j<s.size())
        {
            if(st.find(s[j])==st.end())
            {
                st.insert(s[j]);
                mx=max(mx,j-i+1);
                j++;
            }
            else if(st.find(s[j])!=st.end())
            {
                while(st.find(s[j])!=st.end())
                {
                    st.erase(s[i]);
                    i++;
                }
                st.insert(s[j]);
                mx=max(mx,j-i+1);
                j++;
            }
        }
        return mx;
    }
};
