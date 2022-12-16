struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr&&list2==nullptr) return nullptr;
        if(!list1) return list2; if(!list2) return list1;
        ListNode head;ListNode *end=&head;
        while(list1!=nullptr&&list2!=nullptr)
        {
            if(list1->val<=list2->val){
                end->next=list1;
                list1=list1->next;
            }else{
                end->next=list2;
                list2=list2->next;
            }
            end=end->next;
        }
        if(list1==nullptr) end->next=list2;
        else end->next=list1;
        return head.next;
    }
};