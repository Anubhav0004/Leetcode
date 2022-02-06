class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        ListNode *temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        if(count==1)
        {
            delete head;
            return NULL;
        }
        int idx=count/2;
        temp=head;
        for(int i=0;i<idx-1;i++)
        {
            temp=temp->next;
        }
        ListNode *nxt=temp->next;
        temp->next=temp->next->next;
        delete nxt;
        return head;
    }
};
