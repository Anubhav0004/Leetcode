class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<vector<int>> v;
        vector<double> ans;
        if(!root)
        {
            return ans;
        }
        vector<int> t;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(temp!=NULL)
            {
                t.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
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
        }
        t.clear();
        double sum;
        double val;
        for(int i=0;i<v.size();i++)
        {
            sum=0;
            for(int j=0;j<v[i].size();j++)
            {
                sum+=v[i][j];
            }
            val=sum/v[i].size();
            ans.push_back(val);
        }
        v.clear();
        return ans;
    }
};
////////////////////////////////////////////////////////////////////////////// less space ///////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> v;
        if(!root)
        {
            return v;
        }
        queue<TreeNode*> q;
        TreeNode* temp;
        
        int size;
        double val;
        q.push(root);
        while(!q.empty())
        {
            val=0;
            size=q.size();
            for(int i=0;i<size;i++)
            {
                temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                val+=temp->val;
            }
            v.push_back(val/size);
        }
        return v;
    }
};
