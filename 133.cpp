class Solution {
public:
    void dfs(Node *curr,Node *node,vector<Node*> &vis)
    {
        vis[node->val]=node;
        for(auto i:curr->neighbors)
        {
            if(vis[i->val]==NULL)
            {
                Node *newnode=new Node(i->val);
                (node->neighbors).push_back(newnode);
                dfs(i,newnode,vis);
            }
            else
                (node->neighbors).push_back(vis[i->val]);
        }
    }
    Node* cloneGraph(Node* node) 
    {
        if(!node)
            return NULL;
        vector<Node*> vis(101,NULL);
        Node *copy=new Node(node->val);
        vis[node->val]=copy;
        for(auto it:node->neighbors)
        {
            if(vis[it->val]==NULL)
            {
                Node *newnode=new Node(it->val);
                (copy->neighbors).push_back(newnode);
                dfs(it,newnode,vis);
            }
            else
                (copy->neighbors).push_back(vis[it->val]);
        }
        return copy;
    }
};
