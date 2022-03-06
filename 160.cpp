class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *temp1=headA;
        ListNode *temp2=headB;
        if(!temp1 && !temp2)
            return NULL;
        else if(!temp1)
            return temp2;
        else if(!temp2)
            return temp1;
        while(temp1!=NULL && temp2!=NULL && temp1!=temp2)
        {
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==temp2)
                return temp1;
            if(temp1==NULL)
                temp1=headB;
            if(temp2==NULL)
                temp2=headA;
        }
        return temp1;
    }
};
