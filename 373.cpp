class Solution {
public:
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        ////////////////////////answer////////////////////////
        vector<vector<int>> ans;
        int n=nums1.size(),m=nums2.size();
        if(n==0||m==0) return (ans);
        priority_queue<tuple<int,int, int>> pq;
        pq.push({-nums1[0]-nums2[0],0,0});   // insert initial pair in priority queue
        while(pq.size()&&ans.size()<k)       // pq.size() is necessary coz k can be larger than m*n
        {
            auto topp=pq.top();                // extracting smallest element from pq
            int i=get<1>(topp);
            int j=get<2>(topp);
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});   // insert smallest pair in ans vector
            if(j==0&&i+1<n) pq.push({-nums1[i+1]-nums2[j],i+1,j});   // very important part in whole solN 
											// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84551/simple-Java-O(KlogK)-solution-with-explanation
											// Nicely shown with diagrams in this post			
			
            if(i<n&&j+1<m) pq.push({-nums1[i]-nums2[j+1],i,j+1});
        }
        return (ans); 
       ///// /////////////my approach///////////////////
        priority_queue<pair<int,pair<int,int>>> hp;
        vector<vector<int>> v;
        // if(nums1.size()==0 || nums2.size()==0 || k<=0)
        //     return v;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int sum=nums1[i]+nums2[j];
                if(hp.size()<k)
                {
                    hp.push({sum,{nums1[i],nums2[j]}});
                }
                else if(sum<hp.top().first)
                {
                    hp.pop();
                    hp.push({sum,{nums1[i],nums2[j]}});
                }
            }
        }
        while(!hp.empty())
        {
            auto it=hp.top();
            v.push_back({hp.top().second.first,hp.top().second.second});
            hp.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
