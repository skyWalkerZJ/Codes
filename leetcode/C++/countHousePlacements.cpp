using namespace std;
class Solution {
public:
    int countHousePlacements(int n) {
        int ans=0;int mod=1e9+7;
        int f[n+1];
        f[0]=1;f[1]=2;
        for(int i=2;i<=n;i++)
        {
            f[i]=(f[i-1]+f[i-2])%mod;
        }
        return (f[n]*f[n])%mod;
    }
};