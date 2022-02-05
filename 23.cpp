class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
        {
            return NULL;
        }
        vector<int> v;
        for(int i=0;i<lists.size();i++)
        {
            ListNode *temp=lists[i];
            while(temp!=NULL)
            {
                v.push_back(temp->val);
                temp=temp->next;
            }
        }
        if(v.size()==0)
            return NULL;
        sort(v.begin(),v.end());
        ListNode *dummy=new ListNode(-1);
        ListNode *head=new ListNode(v[0]);
        dummy->next=head;
        ListNode *temp=head;
        for(int i=1;i<v.size();i++)
        {
            ListNode *n =new ListNode(v[i]);
            temp->next=n;
            temp=temp->next;
        }
        delete dummy;
        return head;
    }
};
