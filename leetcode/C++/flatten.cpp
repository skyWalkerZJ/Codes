class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
class Solution {
public:
    Node* flatten(Node* head) {
        if(head==nullptr) return head;
        Node* go=head;
        while(go!=nullptr)
        {
            if(go->child==nullptr)
            {
                go=go->next;
            }else{
                Node* temp=go->next;
                go->next=flatten(go->child);
                go->child->prev=go;
                go->child=nullptr;
                while(go->next!=nullptr)
                {
                    go=go->next;
                }
                if(temp!=nullptr)
                {
                    go->next=temp;
                    temp->prev=go;
                    go=go->next;
                }
            }
        }
        return head;
    }
};