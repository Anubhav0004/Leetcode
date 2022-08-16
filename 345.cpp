class Solution {
public:
    bool isVowel(char word)
    {
        if(word=='a'||word=='e'||word=='i'||word=='o'||word=='u')
            return true;
        if(word=='A'||word=='E'||word=='I'||word=='O'||word=='U')
            return true;
        return false;
    }
        
    string reverseVowels(string s) 
    {
        int n=s.size();
        int i=0,j=n-1;
        while(i<n && j>=0 && i<j)
        {
            if(isVowel(s[i]) && isVowel(s[j]))
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(isVowel(s[i]))
                j--;
            else if(isVowel(s[j]))
                i++;
            else
            {
                i++;
                j--;
            }
        }
        return s;
    }
};
