#include <queue>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct cmp{

    bool operator()(ListNode* n1,ListNode* n2)
    {
        return n1->val>n2->val;
    }
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr) return nullptr;
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        ListNode *go=head;
        while(go!=nullptr)
        {
            pq.emplace(go);
            go=go->next;
        }
        ListNode* ans=new ListNode();
        ListNode* end=ans;
        ans->next=end;
        while(!pq.empty())
        {
            ListNode* top=pq.top();
            pq.pop();
            end->next=top;
            end=end->next;
            end->next=nullptr;
        }
        return ans->next;
    }
};