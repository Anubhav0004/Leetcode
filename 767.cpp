string reorganizeString(string s) 
    { ///////////////////////////////////////////////////////100% solution///////////////////////////////////////////////////////
        string ans="";
        priority_queue<pair<int,char>> hp;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        for(auto it:mp)
        {
            hp.push({it.second,it.first});
        }
        while(hp.size()>=2)
        {
            
            char a=hp.top().second;
            int x=hp.top().first;
            hp.pop();
            char b=hp.top().second;
            int y=hp.top().first;
            hp.pop();
            ans+=a;
            ans+=b;
            x--;
            y--;
            if(x>0)
                hp.push({x,a});
            if(y>0)
                hp.push({y,b});
        }
        if(hp.size()==1 && hp.top().first>1)
        return "";
        if(hp.size()==0) return ans;
        return ans+hp.top().second;
    }
};
