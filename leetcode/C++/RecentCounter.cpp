#include <queue>
using namespace std;
class RecentCounter {
public:
    queue<int> timeStamps;
    int lastTimeStamp;
    RecentCounter() {

    }
    
    int ping(int t) {
        timeStamps.push(t);
        lastTimeStamp=timeStamps.front();
        while(lastTimeStamp+3000<t)
        {
            timeStamps.pop();
            lastTimeStamp=timeStamps.front();
        }
        return timeStamps.size();
    }
};