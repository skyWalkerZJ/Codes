#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB) return nullptr;
        ListNode *A=headA;ListNode *B=headB;
        while(A!=B)
        {
            A=A->next;
            if(A=nullptr) A=headB;
            B=B->next;
            if(B=nullptr) B=headA;
        }
        return A;
    }
};