#include <iostream>
using namespace std;
class Solution {
public:
    int mod=1e9+7;//递归 会超时
    int peopleAwareOfSecret(int n, int delay, int forget) {
        if(delay>=forget) return 1;
        int ans=1;
        int i=1;
        for(;i<=forget&&n>0;i++,n--)
        {
            if(i>delay){
                ans+=peopleAwareOfSecret(n,delay,forget);
                ans=ans%mod;
            }
        }
        if(i>forget&&n>0) ans--;
        return ans%mod;;
    }
 
    const int MOD = 1e9 + 7;//官方解法
    int peopleAwareOfSecret1(int n, int delay, int forget) {
        int sum[n + 1];
        sum[0] = 0, sum[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int f = (sum[max(i - delay, 0)] - sum[max(i - forget, 0)]) % MOD;
            sum[i] = (sum[i - 1] + f) % MOD;
        }
        return ((sum[n] - sum[max(n - forget, 0)]) % MOD + MOD) % MOD; // 防止结果为负数
    }
};


int main()
{
    Solution s;
    cout<<s.peopleAwareOfSecret(684,18,496);
}