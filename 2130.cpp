class Solution {
public:
    int pairSum(ListNode* head) 
    {
        ListNode *temp=head;
        vector<int> v;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        int max=0;
        int j=v.size()-1;
        int sum;
        for(int i=0;i<v.size()/2;i++)
        {
            sum=v[i]+v[j];
            if(sum>max)
                max=sum;
            j--;
        }
        return max;
    }
};
