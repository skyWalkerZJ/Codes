#include <vector>
using namespace std;
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int left=0;int right=0;int ans=INT_MAX;
        for(int n:nums) right=max(right,n);
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            long long have=0;bool flag=true;
            for(int n:nums)
            {
                if(n<=mid)
                {
                    have+=(long long)(mid-n);
                }else{
                    if(have < n-mid) {
                        flag=false;
                        break;
                    }
                    else{
                        have -=(long long)(n-mid);
                    }
                }
            }
            if(have>=0 && flag) {
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};