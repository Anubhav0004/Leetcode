class StockSpanner 
{
public:
    stack<pair<int,int>> st;
    int idx;
    StockSpanner() 
    {
        idx=-1;
    }
    
    int next(int price) 
    {
        idx+=1;
        while(!st.empty() && st.top().second<=price)
            st.pop();
        if(st.empty())
        {
            st.push({idx,price});
            return idx+1;
        }
        int res=st.top().first;
        st.push({idx,price});
        return idx-res;
    }
};
