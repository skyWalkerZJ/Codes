#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* pre=head;ListNode *next=head;
        int x=0;
        while(pre!=NULL)
        {
            if(x==k)
            {
                pre=pre->next;
                next=next->next;
            }else{
                pre=pre->next;
                x++;
            }
        }
        return next->val;
    }
};