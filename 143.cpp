class Solution {
public:
    void reorderList(ListNode* head) 
    {
        vector<ListNode*> v;
        vector<ListNode*> x;
        ListNode *temp=head;
        if(!head->next)
            return;
        while(temp!=NULL)
        {
            v.push_back(temp);
            temp=temp->next;
        }
        int start=0;
        int end=v.size()-1;
        for(int i=0;i<v.size();i++)
        {
            if(start>end)
                break;
            if(i%2==0)
            {
                x.push_back(v[start]);
                start++;
            }
            else
            {
                x.push_back(v[end]);
                end--;
            }
        }
        head=x[0];
        for(int i=0;i<x.size()-1;i++)
        {
            temp=x[i];
            temp->next=x[i+1];
            temp=temp->next;
        }
        temp->next=NULL;
    }
};
