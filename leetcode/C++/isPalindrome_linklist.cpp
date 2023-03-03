
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //找到中间节点 分成两段，后半段翻转，然后前后段完全相同则是回文链表
        int n=0;
        ListNode* go=head;
        while(go!=nullptr)
        {
            n++;
            go=go->next;
        }
        go=head;int i=0;
        while(go!=nullptr)
        {
            i++;
            if(i==(n/2+1)) break;
            go=go->next;
        }
        ListNode *head1=nullptr;
        if(n%2==1) head1=reverseList(go->next);
        else head1=reverseList(go);
        while(head!=nullptr&&head1!=nullptr)
        {
            if(head->val!=head1->val) return false;
            head=head->next;
            head1=head1->next;
        }
        if(head||head1) return false;
        return true;
    }
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