#include <vector>
using namespace std;
class Solution {
public: 
    //2064 分配给商店的最多商品的最小值
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left=1;
        int right=0;int ans=0;
        for(int q:quantities) right=max(right,q);

        while(left<=right)
        {
            int mid=left+(right-left)/2;
            int sum=0;
            for(int k:quantities)
            {
                sum+=((k-1)/mid+1);
            }
            if(sum<=n)
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