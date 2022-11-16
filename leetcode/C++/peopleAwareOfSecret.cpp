#include <iostream>
#include <memory.h>
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
 
    int peopleAwareOfSecret1(int n, int delay, int forget) {
        int f[n];memset(f,0,sizeof(f));
        int cntb=0;f[0]=1;
        for(int i=0;i<n;i++)
        {
            if(i+delay>=n) cntb=(cntb+f[i])%mod;
            for(int j=i+delay;j<min(i+forget,n);j++)
            {
                f[j]=(f[j]+f[i])%mod;
            }
        }
        return (f[n-1]+cntb)%mod;
    }
};


int main()
{
    Solution s;
    cout<<s.peopleAwareOfSecret1(6,2,4);
}