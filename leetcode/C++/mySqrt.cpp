class Solution {
public:
    int mySqrt(int x) {
        int left=0;int right=x;
        int ans=0;
        while(left<=right)
        {
            int mid=(right-left)/2+left;
            long long x1=mid*mid;
            if(x1>(long long)x)
            {
                right=mid-1;
            }else {
                ans=mid;
                left=mid+1;
            }
        }
        return ans;
    }
};