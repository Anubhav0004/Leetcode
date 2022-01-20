class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
//       100% solution
        vector<vector<int>> v;
        queue<TreeNode*> q;
        vector<int> t;
        if(!root)
        {
            return v;
        }
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(temp!=NULL)
            {
                t.push_back(temp->val);
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
            }
            else if(!q.empty())
            {
                v.push_back(t);
                t.clear();
                q.push(NULL);
            }   
        }
        if(t.size()!=0)
            {
                v.push_back(t);
                t.clear();
            }
        return v;
    }
};
