#include <vector>
using namespace std;
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n=stations.size();vector<long long> preSum(n+1);
        vector<long long> power(n);long long left=0;long long right=0;long long ans=0;
        for(int i=1;i<=n;i++)
        {
            preSum[i]=preSum[i-1]+(long long)stations[i-1];
        }
        //前缀和构造power数组
        for(int i=0;i<n;i++)
        {
            power[i]=preSum[min(n,i+r+1)]-preSum[max(0,i-r)];
            right=max(right,power[i]);
        }
        right=right+(long long)k;
        vector<long long> diffs(n);
        diffs[0]=power[0];
        for(int i=1;i<n;i++)
        {
            diffs[i]=power[i]-power[i-1];
        }

        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            long long curNum=0;long long count=0;
            vector<long long> diff(diffs);
            for(int i=0;i<n;i++)
            {
                if(curNum+diff[i]>=mid){
                    curNum+=diff[i];
                    continue;
                }else{
                    long long need=mid-curNum-diff[i];  
                    count+=need;
                    diff[i]+=need;
                    if(i+2*r+1<n) diff[i+2*r+1]-=need;
                    curNum+=diff[i];
                    if(count>k) break;
                }
            }
            if(count<=k)
            {
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v{1,2,4,5,0};
    s.maxPower(v,3,3);
}