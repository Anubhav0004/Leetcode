ListNode* addTwoNumbers(ListNode* L1, ListNode* L2) 
    {
        ListNode *dummy= new ListNode(-1);
        ListNode *temp=dummy;
        int carry=0;
        while(L1 && L2)
        {
            int sum=L1->val+L2->val+carry;
            if(sum>9)
            {
                carry=1;
                sum=sum%10;
            }
            else
                carry=0;
            L1=L1->next;
            L2=L2->next;
            temp->next=new ListNode(sum);
            temp=temp->next;
        }
        while(L1)
        {
            temp->next=L1;
            if(carry==0)
            {
                temp->next=L1;
                return dummy->next;
            }
            L1->val=L1->val+carry;
            if(L1->val>9)
            {
                carry=1;
                L1->val=L1->val%10;
            }
            else
                 carry=0;   
            temp=temp->next;
            L1=L1->next;
        }
        while(L2)
        {
            temp->next=L2;
            if(carry==0)
            {
                temp->next=L2;
                return dummy->next;
            }
            L2->val=L2->val+carry;
            if(L2->val>9)
            {
                carry=1;
                L2->val=L2->val%10;
            }
            else
                 carry=0;   
            temp=temp->next;
            L2=L2->next;
        }
        if(carry==1)
        {
            ListNode *extra=new ListNode(1);
            temp->next=extra;
        } 
        return dummy->next;
    }
