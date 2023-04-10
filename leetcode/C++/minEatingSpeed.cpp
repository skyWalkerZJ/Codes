#include <vector>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=0;
        int left=1;int right=0;
        for(int n:piles)right=max(right,n);
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            //判断以mid的速度能否在h小时内吃完香蕉
            long long sum=0;int n=piles.size();
            for(int i=0;i<n;i++)
            {
                sum+=(long long)((piles[i]-1)/mid+1);
            }
            if(sum<=(long long)h){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};