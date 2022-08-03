class MyCalendar {
private: vector<pair<int,int>> v;
public:
    MyCalendar() 
    {
        
    }
    
    bool book(int start, int end) {
        
        for(auto it:v)
        {
            if(it.first<end && start<it.second)
                return false;
        }
        v.push_back({start,end});
        return true;
    }
};
