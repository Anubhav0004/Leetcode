class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {    
        vector<vector<int>> v;
        if(!root)
            return v;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> t;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node *temp=q.front();
                q.pop();
                for(auto it:temp->children)
                {
                    q.push(it);
                }
                t.push_back(temp->val);
            }
            v.push_back(t);
        }
        return v;
    }
};
