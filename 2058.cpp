class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        // vector<int> v;
        int mx=0;
        int mn=INT_MAX;
        ListNode *prev=head;
        ListNode *curr=head->next;
        int idx=1;
        int first=-1,rec=INT_MIN;
        while(curr->next)
        {
            if(curr->val>prev->val && curr->val>curr->next->val || 
               curr->val<prev->val && curr->val<curr->next->val)
            {
                if(rec>INT_MIN) mn=min(mn,idx-rec);
                if(first==-1)
                {
                    first=idx;
                }
                rec=idx;
            }
            idx++;
            prev=curr;
            curr=curr->next;
        }
        if(mn==INT_MAX) return {-1,-1};
        return {mn,rec-first};
    }
};
////////////////////////////////////////////////////////MY APPROACH////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int> v;
        vector<int> ans;
        int max;
        int min=INT_MAX;
        int i=1;
        ListNode *prev=head;
        ListNode *curr=head->next;
        if(curr->next==NULL)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        while(curr->next!=NULL)
        {
            ListNode *nxt=curr->next;
            if(curr->val>prev->val &&  curr->val>nxt->val || curr->val<prev->val && curr->val<nxt->val)
                v.push_back({i});
            prev=curr;
            curr=nxt;
            i++;
        }
        if(v.size()<=1)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        sort(v.begin(),v.end());
        max=v[v.size()-1]-v[0];
        for(int i=0;i<v.size()-1;i++)
        {
            int diff=v[i+1]-v[i];
            if(diff<min)
                min=diff;
        }
        ans.push_back(min);
        ans.push_back(max);
        return ans;
    }
};

