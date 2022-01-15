class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        vector<string> v(score.size());
        priority_queue<pair<int,int>> hp;
        int count=0;
        int idx;
        string s;
        for(int i=0;i<score.size();i++)
        {
            hp.push({score[i],i});
        }
        while(!hp.empty())
        {
            idx=hp.top().second;
            hp.pop();
            if(count==0)
            {
                v[idx]="Gold Medal";
                count++;
            }
            else if(count==1)
            {
                v[idx]="Silver Medal";
                count++;
            }
            else if(count==2)
            {
                v[idx]="Bronze Medal";
                count++;
            }
            else
            {
                s=to_string(count+1);
                count++;
                v[idx]=s;
            }
        }
        return v;
    }
};
