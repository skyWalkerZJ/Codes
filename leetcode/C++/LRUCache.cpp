#include <unordered_map>
#include <iostream>
using namespace std;
struct DListNode
{
    int key;
    int val;
    DListNode* pre;
    DListNode* next;
    DListNode():key(0),val(0),pre(nullptr),next(nullptr){};
};
class LRUCache {
public:
    int capacity;
    unordered_map<int,DListNode*> hashmap;
    DListNode* head;DListNode* end;
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->head =new DListNode();
        this->end  =new DListNode();
        head->next=end;end->pre=head;
    }
    
    int get(int key) {
        if(hashmap.find(key)==hashmap.end()) return -1;
        pair<int,DListNode*> pair=*hashmap.find(key);
        DListNode* node=pair.second;
        node->next->pre=node->pre;
        node->pre->next=node->next;
        node->next=head->next;
        head->next->pre=node;
        head->next=node;
        node->pre=head;
        return node->val;
    }
    
    void put(int key, int value) {
        if(hashmap.find(key)!=hashmap.end())
        {
            pair<int,DListNode*> pair=*hashmap.find(key);
            DListNode* node=pair.second;
            node->val=value;
            node->next->pre=node->pre;
            node->pre->next=node->next;
            node->next=head->next;
            head->next->pre=node;
            head->next=node;
            node->pre=head;
            return;
        }
        if(hashmap.size()>=capacity){
            DListNode* node=end->pre;
            node->pre->next=end;
            end->pre=node->pre;
            hashmap.erase(hashmap.find(node->key));
        }
        DListNode* newNode=new DListNode();
        newNode->key=key;newNode->val=value;
        hashmap.insert(pair<int,DListNode*>(key,newNode));
        newNode->pre=head;
        newNode->next=head->next;
        head->next->pre=newNode;
        head->next=newNode;
    }
};
int main()
{
    LRUCache *l=new LRUCache(2);
    l->put(1,1);
    l->put(2,2);
    cout<<l->get(1);
}