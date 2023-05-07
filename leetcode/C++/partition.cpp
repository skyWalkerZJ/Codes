struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    //86 分隔链表
    ListNode* partition(ListNode* head, int x) {
        ListNode *less=new ListNode;
        ListNode *lessEnd=less;
        ListNode *noLess=new ListNode;
        ListNode *noLessEnd=noLess;
        ListNode* go=head;
        while(go!=nullptr)
        {
            if(go->val<x)
            {
                lessEnd->next=go;
                go=go->next;
                lessEnd=lessEnd->next;
                lessEnd->next=nullptr;
            }
            else{
                noLessEnd->next=go;
                go=go->next;
                noLessEnd=noLessEnd->next;
                noLessEnd->next=nullptr;
            }
        }
        lessEnd->next=noLess->next;
        return less->next;
    }
};