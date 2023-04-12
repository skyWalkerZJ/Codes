#include <vector>
using namespace std;
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left=1;int right=0;int ans=0;
        for(int c:candies)
        right=max(right,c);
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            //判断一堆为mid个能否满足条件
            long long sum=0;
            for(int n:candies)
            {
                sum+=(long long)(n/mid);
            }
            if(sum>=k)
            {
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        return ans;
    }
};