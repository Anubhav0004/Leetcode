class Solution {
public:
    bool reorderedPowerOf2(int n)
    {
        unordered_map<int,vector<int>> mp;
        int x=pow(10,9);
        for(int i=1;i<=x;i=i*2)
        {
            int k=i;
            vector<int> v(10,0);
            while(k)
            {
                int r=k%10;
                v[r]++;
                k=k/10;
            }
            mp[i]=v;
        }
        vector<int> count(10,0);
        while(n>0)
        {
            int r=n%10;
            count[r]++;
            n=n/10;
        }
        for(int i=1;i<=x;i=i*2)
        {
            vector<int> t=mp[i];
            bool flag=0;
            for(int j=0;j<10;j++)
            {
                if(t[j]!=count[j])
                    flag=1;
            }
            if(flag==0)
                return true;
        }
        return false;
    }
};
