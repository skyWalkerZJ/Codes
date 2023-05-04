#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct cmp
{
    bool operator()(vector<int>a,vector<int> b)
    {
        return a[1]>b[1];
    }
};

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        int total=0;
        sort(courses.begin(),courses.end(),cmp());
        for(vector<int> v:courses)
        {
            if(v[0]+total<=v[1])
            {
                total+=v[0];
                pq.push(v[0]);
            }else{
                if(!pq.empty()&&v[0]<pq.top())
                {
                    total-=pq.top();
                    pq.pop();
                    pq.push(v[0]);
                    total+=v[0];
                }
            }
        }
        return pq.size();
    }
};