#include <stack>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1,s2;
        ListNode *start=l1;
        while(start!=nullptr) 
        {
            s1.push(start);
            start=start->next;
        }
        start=l2;
        while(start!=nullptr)
        {
            s2.push(start);
            start=start->next;
        }
        int jinwei=0;ListNode* head;
        while(!s1.empty()&&!s2.empty())
        {
            ListNode *node1=s1.top();
            s1.pop();
            ListNode *node2=s2.top();
            s2.pop();
            int current=(node1->val+node2->val+jinwei)%10;
            jinwei=(node1->val+node2->val+jinwei)/10;
            node1->val=current;
            node1->next=head;
            head=node1;
        }
        if(!s1.empty())
        {
            ListNode *node=s1.top();
            s1.pop();
            int current=(node->val+jinwei)%10;
            jinwei=(node->val+jinwei)/10;
            node->val=current;
            node->next=head;
            head=node;
        }
        if(!s2.empty())
        {
            ListNode *node=s2.top();
            s2.pop();
            int current=(node->val+jinwei)%10;
            jinwei=(node->val+jinwei)/10;
            node->val=current;
            node->next=head;
            head=node;
        }
        if(jinwei!=0)
        {
            ListNode node;
            node.val=jinwei;
            node.next=head;
            head=&node;
        }
        return head;
    }
};