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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return head;
        if(head->next==nullptr) return head;
        ListNode *start=nullptr;
        while(head!=nullptr)
        {
            ListNode *next=head->next;
            head->next=start;
            start=head;
            head=next;
        }
        return start;
    }
};