#include <queue>
using namespace std;
class MovingAverage {
public:
    /** Initialize your data structure here. */
    int size;
    queue<int> queue;double sum=0;
    MovingAverage(int size) {
        this->size=size;
    }
    
    double next(int val) {
        queue.push(val);
        sum+=val;
        if(queue.size()>size){
            sum-=queue.front();
            queue.pop();
        }
        return sum/queue.size();
    }
};