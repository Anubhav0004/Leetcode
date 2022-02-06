class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head)
            return NULL;
        map<int,int> mp;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            mp[temp->val]++;
            temp=temp->next;
        }
        vector<int> v;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==1)
                v.push_back(it->first);
        }
        ListNode *dummy=new ListNode(0);
        temp=dummy;
        for(int i=0;i<v.size();i++)
        {
            ListNode *n=new ListNode(v[i]);
            temp->next=n;
            temp=temp->next;
        }
        head=dummy->next;
        delete dummy;
        return head;
    }
};
