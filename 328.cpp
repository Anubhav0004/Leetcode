class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head)
            return NULL;
        vector<ListNode*> v1;
        vector<ListNode*> v2;
        ListNode *temp=head;
        int i=0;
        while(temp!=NULL)
        {
            if(i%2==0)
                v1.push_back(temp);
            else
                v2.push_back(temp);
            temp=temp->next;
            i++;
        }
        head=v1[0];
        temp=head;
        for(int i=0;i<v1.size()-1;i++)
        {
            temp->next=v1[i+1];
            temp=temp->next;
        }
        for(int i=0;i<v2.size();i++)
        {
            temp->next=v2[i];
            temp=temp->next;
        }
        temp->next=NULL;
        return head;
    }
};
