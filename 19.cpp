class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(n==1 & !head->next)
        {
            return NULL;
        }
        ListNode *temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        if(count==n)
        {
            ListNode *temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        temp=head;
        int pos=count-n;
        count=0;
        while(temp!=NULL)
        {  
            if(count==pos-1)
            {
                ListNode* curr=temp->next;
                temp->next=curr->next;
                delete curr;
                break;
            }
            temp=temp->next;
            count++;
        }
        return head;
    }
};
