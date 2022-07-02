class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) 
    {
        hc.push_back(0);
        hc.push_back(h);
        vc.push_back(0);
        vc.push_back(w);
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int n=hc.size();
        long mod=1000000007;
        // long mod=1e9+7; /////////these aprooaches work but are less efficient///////////////////////////////
        // long diff1=(hc[0]-0)%mod;
        // long diff2=(vc[0]-0)%mod;
        for(int i=1;i<n;i++)
        {
            diff1=max(diff1,((hc[i]-hc[i-1])%mod));
        }
        n=vc.size();
        for(int i=1;i<n;i++)
        {
            diff2=max(diff2,((vc[i]-vc[i-1])%mod));
        }
        return (diff1*diff2)%mod;
    }
};
