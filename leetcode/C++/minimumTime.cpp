#include <vector>
using namespace std;
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left=1;int m=0;
        for(int t:time)
        {
            m=max(m,t);
        }
        long long ans=0;
        long long right=(long long)m*(long long)totalTrips;
        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            //判断mid时间内的旅途数目是否大于totalTrips，如果大于还可以再缩短时间
            long long sum=0;
            for(int t:time)
            {
                sum+=(mid/t);
            }
            if(sum>=totalTrips)
            {
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};