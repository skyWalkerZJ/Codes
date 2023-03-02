#include <vector>
#include <queue>
using namespace std;
class KthLargest {
//优先队列
public:
    int k;
    priority_queue<int,vector<int>,greater<int>> q;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto s:nums)
        {
            add(s);
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size()>k) q.pop();
        return q.top();
    }
};