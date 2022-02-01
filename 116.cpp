class Solution {
public:
    Node* connect(Node* root) 
    {   
        if(!root)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<Node*> v;
            for(int i=0;i<size;i++)
            {
                Node *temp=q.front();
                q.pop();   
                v.push_back(temp);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);   
            }
            for(int i=0;i<v.size()-1;i++)
            {
                v[i]->next=v[i+1];
            }
            v[v.size()-1]->next=NULL;
        }
        return root;
    }
};
