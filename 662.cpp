class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            int min=q.front().second;
            int first,last;
            for(int i=0;i<size;i++)
            {
                int curr=q.front().second-min;
                TreeNode *temp=q.front().first;
                q.pop();
                if(i==0)
                    first=curr;
                if(i==size-1)
                    last=curr;
                if(temp->left)
                    q.push({temp->left,2*curr+1});
                if(temp->right)
                    q.push({temp->right,2*curr+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};
