#include <vector>
using namespace std;
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right=0;int ans=0;
        for(int i:nums)right=max(right,i);
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            int sum=0;
            for(int n:nums)
            {
                sum+=((n-1)/mid+1);
            }

            if(sum<=threshold)
            {
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};