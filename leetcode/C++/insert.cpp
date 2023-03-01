class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head==nullptr) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        auto cur = head;
        while(cur->next!=head){
            if(cur->next->val<cur->val){
                if(cur->next->val>=insertVal) break;
                else if(cur->val<=insertVal) break;
            }
            if(cur->val<=insertVal&&cur->next->val>=insertVal) break;
            cur = cur->next;
        }
        cur->next = new Node(insertVal, cur->next);
        return head;
    }
};