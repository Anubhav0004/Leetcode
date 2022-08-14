class Solution {////////////always use bfs for finding shortest path/////////////////////
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        bool end =false;
        unordered_set<string> words;
        for(auto word:wordList)
        {
            if(endWord.compare(word)==0)
                end=true;
            words.insert(word);
        }
        if(!end)
            return 0;
        queue<string> q;
        q.push(beginWord);
        int depth=0;
        while(!q.empty())
        {
            depth+=1;
            int lsize=q.size();
            while(lsize--)
            {
                string curr=q.front();
                q.pop();
                for(int i=0;i<curr.length();i++)
                {
                    string temp=curr;
                    for(char c='a';c<='z';c++)
                    {
                        temp[i]=c;
                        if(curr.compare(temp)==0)
                            continue;
                        if(curr.compare(endWord)==0)
                            return depth;
                        if(words.find(temp)!=words.end())
                        {
                            q.push(temp);
                            words.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
