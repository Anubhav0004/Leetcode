class Solution {
public:
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode *temp=head->next;
        int sum=0;
        ListNode *prev=head;
        head=prev;
        while(temp->next!=NULL)
        {
            sum+=temp->val; //3+1
            // cout<<sum<<" ";
            if(temp->next->val==0)
            {
                temp->next->val=sum;
                prev->next=temp->next;//4
                prev=prev->next;
                sum=0;
                temp=temp->next;
            }
            if(temp->next)
            temp=temp->next;
        }
        // temp=head->next;
        // while(temp!=NULL)
        // {
        //     cout<<temp->val<<" ";
        //     temp=temp->next;
        // }
        return head->next;
    }
};
