#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i=0;
        ListNode *phead=new ListNode(-1);
        phead->next=head;ListNode* pre=phead;
        ListNode *lastHead=NULL;
        ListNode *next=NULL;ListNode *cur=NULL;ListNode *end=NULL;ListNode *endForst=NULL;
        while(pre!=NULL)
        {
            next=pre->next;
            if(i==left-1)
            {
                lastHead=pre;
            }else if(i>=left&&i<right)
            {
                if(end==NULL) end=pre;
                pre->next=cur;
                cur=pre;
            }if(i==right)
            {
                endForst=next;
                if(end==NULL) end=pre;
                pre->next=cur;
                cur=pre;
            }
            pre=next;
            i++;
        }
        lastHead->next=cur;end->next=endForst;
        return phead->next;
    }
};