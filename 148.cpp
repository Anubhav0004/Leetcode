class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        if(!head)
            return NULL;
        ListNode *temp=head;
        vector<int> v;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        sort(v.begin(),v.end());
        temp=head;
        for(int i=0;i<v.size();i++)
        {
            temp->val=v[i];
            temp=temp->next;
        }
        return head;
    }
};
