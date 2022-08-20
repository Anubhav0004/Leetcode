class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        int i=0,res;
        priority_queue<int> hp;
        for(res=0;startFuel<target;res++)
        {
            while(i<stations.size() && stations[i][0]<=startFuel)
            {
                hp.push(stations[i][1]);
                i++;
            }
            if(hp.empty())
                return -1;
            startFuel+=hp.top();
            hp.pop();
        }
        return res;
    }
};
