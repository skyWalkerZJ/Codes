struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class solution
{
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head;
        ListNode *low=head;ListNode node;
        ListNode *phead=&node;
        phead->next=head;
        ListNode* ans=phead;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
            if(fast==nullptr) break;
        }
        
        while(fast!=nullptr&&low!=nullptr)
        {
            fast=fast->next;
            phead=phead->next;
        }
        if(phead->next!=nullptr) phead->next=phead->next->next;
        return ans->next;
    }
};