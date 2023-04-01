#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
class Solution {
public:
    int res=INT_MAX;
    int numSquares(int n) {
        vector<int> nums{1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676,729,784,841,900,961,1024,1089,1156,1225,1296,1369,1444,1521,1600,1681,1764,1849,1936,2025,2116,2209,2304,2401,2500,2601,2704,2809,2916,3025,3136,3249,3364,3481,3600,3721,3844,3969,4096,4225,4356,4489,4624,4761,4900,5041,5184,5329,5476,5625,5776,5929,6084,6241,6400,6561,6724,6889,7056,7225,7396,7569,7744,7921,8100,8281,8464,8649,8836,9025,9216,9409,9604,9801,10000};
        vector<int> ans;
        backtrack(nums,n,ans);
        return res;
    }
    void backtrack(vector<int>& nums,int n,vector<int>& ans)
    {
        if(n==0){
            res=min(res,(int)ans.size());
        }
        if(ans.size()>res) return;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]<=n) {
                ans.push_back(nums[i]);
                backtrack(nums,n-nums[i],ans);
                ans.pop_back();
            }else{
                break;
            }
        }
    }

    int numSquares(int n) {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }
};
int main()
{
    for(int i=0;i<=100;i++)
    {
        cout<<i*i<<",";
    }
    return 0;
}