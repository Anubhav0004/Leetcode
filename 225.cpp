class MyStack {    //////////////////////////100%////////////////////////////////
public:
    queue<int> q1;
    queue<int> q2;
    int N;
    MyStack() {
        
        N=0;
    }
    
    void push(int x) 
    {
        q1.push(x);
        N++;
    }
    
    int pop() 
    {
        if(q1.empty())
        {
            return -1;
        }
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int val=q1.front();
        q1.pop();
        N--;
        swap(q1,q2);
        return val;
    }
    
    int top() 
    {
        if(q1.empty())
        {
            return -1;
        }
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int val=q1.front();
        q2.push(q1.front());
        q1.pop();
        swap(q1,q2);
        return val;
    }
    
    bool empty() 
    {
        if(N==0)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
