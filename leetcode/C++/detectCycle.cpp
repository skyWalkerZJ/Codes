#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head;
        ListNode *low=head;
        while(fast!=nullptr&&fast->next!=nullptr)
        {
            fast=fast->next->next;
            low=low->next;
            if(fast==low) break;
        }
        if(fast==nullptr) return nullptr;
        ListNode *start=head;
        while(start!=low)
        {
            start=start->next;
            low=low->next;
        }
        return start;
    }
};