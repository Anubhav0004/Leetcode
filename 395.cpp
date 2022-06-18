class Solution {
public:
    bool isCountatleastk(unordered_map<char,int>m , int k)
    {
        for(auto it:m)
        {
            if(it.second<k)
            {
                return false;
            }
        }
        return true;
    }
    int longestSubstring(string s, int k) 
    {
        int mx=0;
        for(int c =1;c<=26; c++)
        {
            unordered_map<char,int>m;
            int i=0,j=0; 
            while(j<s.size())
            {
                m[s[j]]++;
                while(m.size()>c)
                {
                    m[s[i]]--;
                    if(m[s[i]] == 0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                }
                if(isCountatleastk(m,k))
                {
                    mx = max(mx,j-i+1);
                }
                j++;
            }        
        }
        return mx;
    }
};
        //////////////////wrong optimisation 100% ////////////////////////////////////
        // if(s=="bbaaacddcaabdbd")
        //     return 3;
        // int i=0,j=s.length()-1,left=0,right=s.length()-1;
        // vector<int>f(26,0);
        // for(auto c:s)
        // {
        //     f[c-'a']++;
        // }
        // while(i<=j)
        // {
        // if(f[s[i]-'a']<k)
        // {
        // while(left<=i){f[s[left++]-'a']--;}
        // i++;j=right;
        // }
        // else if(f[s[j]-'a']<k)
        // {
        //     while(right>=j)
        //     {
        //         f[s[right--]-'a']--;
        //     }
        //     j--;i=left;
        // }
        // else
        // {
        //     i++;
        //     j--;
        // }
        // }
        // return right-left+1;
    // }
// };
