class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> hp;
        if(stones.size()==1)
        {
            return stones[0];
        }
        for(int i=0;i<stones.size();i++)
        {
            hp.push(stones[i]);
        }
        while(hp.size()>1)
        {
            int y=hp.top();
            hp.pop();
            int x=hp.top();
            hp.pop();
            if(y>x)
            {
                // int val=y-x;
                hp.push(y-x);
            }
        }
        return hp.empty()?0:hp.top();
    }
};
