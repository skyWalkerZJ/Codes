#include <stack>
#include <queue>
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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        queue<ListNode*> q;ListNode* ans=nullptr;ListNode *end=nullptr;
        ListNode* p=head;int count=0;
        while(p!=nullptr)
        {
            s.push(p);
            q.push(p);
            count++;
            p=p->next;
        }
        if(count<2) return;
        for(int i=0;i<count/2;i++)
        {
            ListNode* node1=q.front();
            q.pop();
            ListNode* node2=s.top();
            s.pop();
            node1->next=node2;
            if(ans==nullptr) 
            {
                ans=node1;end=node2;
            }else{
                end->next=node1;
                end=node2;
            }
        }
        if(count%2==1){
            ListNode * node=s.top();
            end->next=node;
            end=node;
        }
        end->next=nullptr;
        return ;
    }
};