class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        int l=a-1;
        int r=b+1;
        int count=0;
        ListNode *temp=list1;
        while(temp!=NULL && count<a-1)
        {
            temp=temp->next;
            count++;
        }
        ListNode *nxt=temp->next;
        count++;
        temp->next=list2;
        while(nxt!=NULL && count<b+1)
        {
            ListNode *todel=nxt;
            nxt=nxt->next;
            delete todel;
            count++;
        }
        ListNode *temp2=list2;
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=nxt;
        return list1;
    }
};
