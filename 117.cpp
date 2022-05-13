class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root)
            return NULL;
        queue<Node*> q;
        vector<vector<Node*>> v;
        q.push(root);
        while(!q.empty())
        {
            vector<Node*> v1;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node *a=q.front();
                q.pop();
                v1.push_back(a);
                if(a->left)
                    q.push(a->left);
                if(a->right)
                    q.push(a->right);
            }
            v.push_back(v1);
        }
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size()-1;j++)
            {
                v[i][j]->next=v[i][j+1];
            }
            v[i][v[i].size()-1]->next=NULL;
        }
        return root;
    }
};
